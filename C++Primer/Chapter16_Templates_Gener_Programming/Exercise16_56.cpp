/*
 *教材背景：errorMsg 可变参数模板，内部调用之前写的debug_rep，打印任意多个参数的调试信息。
 6.2.6 节旧版error_msg：重载可变参数函数，用 initializer_list 版本。
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

// debug_rep 教材原版：使用 ostringstream，支持string
template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p)
{
    ostringstream ret;
    ret << "pointer: " << p << ", value=" << *p;
    return ret.str();
}

template <typename T>
ostream &print(ostream &os, const T &t)
{
    os << t << " ";
    return os;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &...rest)
{
    os << t << " ";
    return print(os, rest...);
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args &...rest)
{
    return print(os, debug_rep(rest)...); // errorMsg：对参数包每个元素单独调用 debug_rep，包展开 debug_rep(rest)...
}

int main(int argc, char const *argv[])
{
    int x = 10;
    // 测试：多个不同类型实参
    errorMsg(cout, 42, string("error"), &x, 3.14);

    cout << '\n';

    errorMsg(cout, 99);

    /*
    42 error pointer: 0x7686bffdac, value=10 3.14
    99
    */
    return 0;
}
