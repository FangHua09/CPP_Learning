/*
 *把 debug_rep 的 char* /const char* 重载改为模板特例化

 template<typename T> string debug_rep(const T &t);
 template<typename T> string debug_rep(T *p);

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

// 模板A：任意const引用
template <typename T>
string debug_rep(const T &t)
{
    cout << "模板A：任意const引用" << '\n';
    return to_string(t);
}

// 模板B：指针版本
template <typename T>
string debug_rep(T *p)
{
    cout << "模板B：指针版本" << '\n';
    return string("pointer:") + to_string(*p);
}

// 只特例化指针版本的模板 因为他们是指针类型
// 特例化 const char*
template <>
string debug_rep<const char>(const char *p)
{
    cout << "特例化 const char*" << '\n';
    return string("pointer:") + p;
}

// 特例化 char*
template <>
string debug_rep<char>(char *p)
{
    cout << "特例化 char*" << '\n';
    return string("pointer:") + p;
}

int main()
{
    char arr[] = "hello";
    char *p1 = arr; // 合法，arr不是字符串常量
    const char *p2 = "world";
    cout << debug_rep(p1) << endl;
    cout << debug_rep(p2) << endl;
    return 0;
}

/*
特例化 char*
pointer:hello
特例化 const char*
pointer:world
*/