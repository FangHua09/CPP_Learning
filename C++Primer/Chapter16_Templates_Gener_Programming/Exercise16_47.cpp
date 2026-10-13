/*
 *题目：编写你自己版本的翻转函数 flip，通过调用接受左值和右值引用参数的函数来测试它。
 知识点：万能引用 + std::forward 完美转发；flip 的作用：接收一个二元可调用对象，把两个实参顺序反转传给该函数。


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

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(forward<T2>(t2), forward<T1>(t1));
}

void f1(int &a, int &b)
{
    cout << "【左值引用版本】 a = " << a << ", b = " << b << endl;
    a = b = 0;
}
// 测试函数2：接收右值引用
void f2(int &&a, int &&b)
{
    cout << "【右值引用版本】 a = " << a << ", b = " << b << endl;
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 20;
    cout << "===== 测试左值实参 =====" << endl;
    cout << "调用前 x=" << x << ", y=" << y << endl;
    flip(f1, x, y);
    cout << "调用后 x=" << x << ", y=" << y << endl;

    cout << "\n===== 测试右值实参 =====" << endl;
    flip(f2, 100, 200);
    return 0;
}

// // ============== 三个 flip 版本对比 ==============

// // 版本1：值传递（参数全部拷贝）
// template <typename F, typename T1, typename T2>
// void flip1(F f, T1 t1, T2 t2)
// {
//     f(t2, t1);
// }

// // 版本2：万能引用，但内部直接传参（不保持值类别）
// template <typename F, typename T1, typename T2>
// void flip2(F f, T1 &&t1, T2 &&t2)
// {
//     // t1、t2 是“有名字的右值引用”，属于左值，会丢失右值属性
//     f(t2, t1);
// }

// // 版本3：完美转发（std::forward 保持原始值类别）
// template <typename F, typename T1, typename T2>
// void flip3(F f, T1 &&t1, T2 &&t2)
// {
//     // forward<T>：左值保持左值，右值保持右值
//     f(forward<T2>(t2), forward<T1>(t1));
// }

// // ============== 三种目标函数 ==============

// // ① 值参数
// void f1(int a, int b)
// {
//     cout << "[f1 值参数]  a=" << a << "  b=" << b << '\n';
// }

// // ② 左值引用参数
// void f2(int &a, int &b)
// {
//     cout << "[f2 左值引用]  a=" << a << "  b=" << b << '\n';
// }

// // ③ 右值引用参数
// void f3(int &&a, int &&b)
// {
//     cout << "[f3 右值引用]  a=" << a << "  b=" << b << '\n';
// }

// int main()
// {
//     int x = 10, y = 20; // 左值变量，用来测试左值引用场景

//     cout << "========== 1. flip1：值传递版本 ==========\n";
//     flip1(f1, 1, 2); // ✅ 可以：值拷贝，f1 接收值
//     // flip1(f2, 1, 2); // ❌ 编译错误：右值字面量不能绑定到非const左值引用 int&
//     // flip1(f3, 1, 2); // ❌ 编译错误：t1/t2 是局部左值变量，不能传给 int&& 右值引用

//     cout << "\n========== 2. flip2：万能引用但不转发 ==========\n";
//     flip2(f1, 1, 2); // ✅ 可以：f1 接收值
//     flip2(f2, x, y); // ✅ 可以：x/y 是左值，推导为左值引用，传给 f2
//     // flip2(f3, 1, 2);   // ❌ 编译错误：t1/t2 是命名变量（左值），丢失右值属性，不能传给 int&&

//     cout << "\n========== 3. flip3：完美转发版本 ==========\n";
//     flip3(f1, 1, 2); // ✅ 可以：右值保持右值，f1 接收值
//     flip3(f2, x, y); // ✅ 可以：左值保持左值，正常绑定 int&
//     flip3(f3, 1, 2); // ✅ 可以：右值保持右值，正常绑定 int&&

//     cout << "\n----- 验证 flip3 左值场景 -----\n";
//     flip3(f2, x, y);
//     cout << "原变量 x=" << x << "  y=" << y << '\n';

//     return 0;
// }
