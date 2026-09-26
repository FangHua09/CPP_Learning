/*
为什么拷贝并交换版本不理想
拷贝交换版：HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
不管传入左值还是右值，都会先构造一个 rhs 临时对象：
左值：拷贝构造 rhs；
右值：移动构造 rhs；
然后 swap。
缺点：不管移动还是拷贝场景，都必须创建临时对象。纯移动场景下，完全没必要创建临时对象，浪费开销。

什么时候对成员使用 std::move？区分【内置类型】和【类类型成员】
✅情况 1：成员是类类型（有移动语义），需要用std::move
示例：成员是std::string s; std::vector<int> vec;
class Demo{
public:
    std::string s;
    std::vector<int> vec;
    Demo(Demo&& orig){
        s = std::move(orig.s);   // ✅必须move：调用string的移动赋值，接管orig.s内部char数组，不拷贝字符串
        vec = std::move(orig.vec);
        // 移动之后 orig.s、orig.vec 进入合法但未指定状态，不需要手动置空，string/vector自己管理
    }
};
orig.s 是左值（orig 是左值引用，orig.s 是成员变量名字，属于左值）。
如果不写std::move(orig.s)，会调用拷贝赋值，做深拷贝，失去移动语义性能优势。
std::move强制把左值转为右值引用，触发移动版本。
规则：类类型成员，在移动构造 / 移动赋值里面，访问源对象的成员，它本身是左值，必须 std::move 才会走移动语义。

❌情况 2：成员是内置类型：int、指针、double，不要用 std::move
struct HasPtr{
    std::string* ps; //指针，内置类型
    int i;

    HasPtr(HasPtr&& orig){
        ps = orig.ps;          // ✅直接拷贝指针，move没有收益
        i = orig.i;
        orig.ps = nullptr;     // 手动置空！！！
        orig.i = 0;
    }
};
原因：内置类型没有移动构造函数。移动内置对象等价于拷贝。std::move(orig.ps)不会改变指针，不会把 orig.ps 变成 nullptr，只是多一层类型转换，代码迷惑人。
误区：很多新手以为std::move会把源变量清空。std::move 仅仅做类型转换！不会修改变量！ 清空源对象这件事要你手写代码完成（指针置空）。只有标准库容器 /string 的移动赋值内部会去修改源对象。

拷贝交换版本：永远生成临时对象；
分开版本：左值触发拷贝；右值直接移动，不产生临时对象，效率更高。
    // 拷贝赋值
    HasPtr& operator= (const HasPtr& rhs){
        if(this == &rhs) return *this;
        auto newp = new string(*rhs.ps);
        delete ps; // 删除自己的空间
        i = rhs.i;
        ps = newp;
        return *this;
    }

    // 移动赋值
    HasPtr& operator= (HasPtr&& rhs){
        if(this == &rhs) return *this;
        // 还是要记得释放自己的资源
        delete ps;
        // 内置类型拷贝赋值
        ps = rhs.ps;
        i = rhs.i;
        //将右侧运算对象的指针内置复合类型成员置空
        rhs.ps = nullptr;
        rhs.i = 0;
        return *this;
    }
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <numeric>
#include <bitset>
#include <climits>
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    // 普通构造函数
    HasPtr(): ps(nullptr), i(0) {}
    HasPtr(const string &s, int i) : ps(new string(s)), i(i) {}

    // 析构
    ~HasPtr()
    {
        delete ps; // 析构要自己额外delete 指向堆空间的裸指针成员
    }

    // 拷贝构造
    HasPtr(const HasPtr &orig)
    {
        this->ps = new string(*orig.ps); // 左运算对象还没有构造，要分配新堆内存
        // 指向一样的值 但是内存空间不一样
        this->i = orig.i; // 内置类型直接拷贝
    }

    // 移动构造
    HasPtr(HasPtr &&orig){
        ps = orig.ps;
        i = orig.i;
        orig.i = 0;
        orig.ps = nullptr;
    }

    // 拷贝/移动赋值运算符合一版本
    //不管移动还是拷贝场景，都必须创建临时对象。纯移动场景下，完全没必要创建临时对象，浪费开销。
    // HasPtr& operator=(HasPtr rhs){
    //     using std::swap; // 开启ADL 如果没加std::自动匹配自己写的
    //     swap(*this, rhs);
    //     return *this;
    // }

    // 拷贝赋值
    HasPtr& operator= (const HasPtr& rhs){
        if(this == &rhs) return *this;
        auto newp = new string(*rhs.ps);
        delete ps; // 删除自己的空间
        i = rhs.i;
        ps = newp;
        return *this;
    }

    // 移动赋值
    HasPtr& operator= (HasPtr&& rhs){
        if(this == &rhs) return *this;
        // 还是要记得释放自己的资源
        delete ps;
        // 内置类型拷贝赋值
        ps = rhs.ps;
        i = rhs.i;
        //将右侧运算对象的指针内置复合类型成员置空
        rhs.ps = nullptr;
        rhs.i = 0;
        return *this;
    }
    

    // 定义<运算符 `bool operator<(...) const`
    //`sort`接收 const 引用对象，**比较运算符必须是 const 成员**，否则编译报错 / 不使用该比较函数。
    bool operator<(const HasPtr &rhs)const
    {
        return *ps < *(rhs.ps);
    }

private:
    string *ps;
    int i;
};
// swap函数 写外面 但是添加友元
void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "【执行HasPtr自定义swap】" << endl;
    // 通过std::swap进入类内部去交换他们的内置类型成员，如果有类成员应该它里面要也要定义swap
    std::swap(lhs.i, rhs.i);
    // 默认swap交换指针，不要值拷贝
    std::swap(lhs.ps, rhs.ps);
}
// 测试
int main()
{
    vector<HasPtr> vec;
    vec.emplace_back("D", 1);
    vec.emplace_back("B", 2);
    vec.emplace_back("A", 3);
    vec.emplace_back("C", 4);
    
    // ADL参数依赖查找：优先找HasPtr的swap，而不是std::swap
    using std::swap;
    sort(vec.begin(), vec.end());

    return 0;
}