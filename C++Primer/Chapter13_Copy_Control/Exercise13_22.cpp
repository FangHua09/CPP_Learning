/*
题目描述
假定我们希望 HasPtr 的行为像一个值。即，对于对象所指向的 string 成员，每个对象都有一份自己的拷贝。为 HasPtr 编写拷贝构造函数和拷贝赋值运算符。
HasPtr 原始成员：string *ps; int i;，ps 指向堆上分配的 string。值语义：拷贝时做深拷贝，新对象拥有独立的 string 副本，修改一个对象不会影响另一个。
知识点
值语义（深拷贝）：拷贝对象时，重新分配堆内存，复制底层数据，两个对象完全独立。
拷贝构造函数：用已有对象初始化新对象。
拷贝赋值运算符：处理自赋值安全，先分配新资源，再释放旧资源，防止内存泄漏。
析构函数：释放 ps 指向的堆内存（值语义必须配套析构）。
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

class HasPtr {
public:
    HasPtr() = default;
    HasPtr(const string& s, int i): ps(new string(s)), i(i){}
    ~HasPtr() {
        delete ps; // 析构要自己额外delete 指向堆空间的裸指针成员
    }

    // 拷贝构造
    HasPtr(const HasPtr& orig){
        this->ps = new string(*orig.ps); // 左运算对象还没有构造，要分配新堆内存
        // 指向一样的值 但是内存空间不一样
        this->i = orig.i; // 内置类型直接拷贝
    }

    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr& rhs){
        // 值语义做深拷贝，左侧原指向对象销毁，分配新内存，指向一样的对象的值（互不相干）
        auto newp = new string(*rhs.ps); // 指向新地址但内容一样的临时指针
        delete this->ps; // 释放左运算对象指针成员堆空间
        this->ps = newp;
        this->i = rhs.i;
        return *this; // 返回左运算对象的引用
    }
    
private:
    string *ps;
    int i;
};

#include <iostream>
int main()
{
    HasPtr a("hello", 5);
    HasPtr b = a;   // 调用拷贝构造，深拷贝
    HasPtr c("test", 6);
    c = a;          // 调用拷贝赋值，深拷贝
    return 0;
}
