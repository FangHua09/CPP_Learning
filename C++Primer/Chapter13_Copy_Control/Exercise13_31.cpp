/*
为 HasPtr 定义<运算符；创建vector<HasPtr>，添加元素，sort，观察 swap 何时调用。
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
    HasPtr(): ps(nullptr), i(0) {}
    HasPtr(const string &s, int i) : ps(new string(s)), i(i) {}
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

    // 拷贝赋值运算符
    HasPtr &operator=(const HasPtr &rhs)
    {
        // 值语义做深拷贝，左侧原指向对象销毁，分配新内存，指向一样的对象的值（互不相干）
        auto newp = new string(*rhs.ps); // 指向新地址但内容一样的临时指针
        delete this->ps;                 // 释放左运算对象指针成员堆空间
        this->ps = newp;
        this->i = rhs.i;
        return *this; // 返回左运算对象的引用
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