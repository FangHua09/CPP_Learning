/*
问题：为前面练习中的 HasPtr 类添加一个析构函数。
HasPtr：string *ps; int i;，ps 指向堆上 string。析构要释放 ps 指向的动态内存。
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
public:
    // 单参数构造
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

    // 拷贝构造函数：深拷贝
    HasPtr(const HasPtr& orig){
        ps = new string(*(orig.ps));
        i = orig.i;
    }

    // 拷贝赋值运算符
    HasPtr& operator= (const HasPtr& rhs){
        // 左侧运算对象隐式传入this， 右侧运算对象作为实参传入
        // 先拷贝右侧资源到临时，防止自赋值，同时避免释放原资源后读取rhs
        // 左侧原来ps指向的动态内存需要delete
        auto newp = new string(*rhs.ps); // 先保存右侧资源
        delete this->ps; // 释放左值的ps资源
        this->ps = newp; // 左值的ps开辟了新动态内存，指向的是一样的值，而不是一样的地址
        this->i = rhs.i;
        return *this;
    }

    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};