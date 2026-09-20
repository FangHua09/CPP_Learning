/*
【题目描述】
说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
概念区别
形参：函数参数列表定义；函数调用时创建，函数结束销毁；每次调用都会重新初始化，存储在栈上。
普通局部变量：函数体内定义（不加 static）；进入函数创建，函数结束销毁；每次调用重新创建，栈内存；内置类型默认无初始化。
局部静态变量 static：函数体内static修饰；只在第一次调用初始化 1 次；生命周期贯穿整个程序，存储在静态存储区；函数返回不会销毁，保留上一次的值；内置类型默认初始化为 0。
*/

#include <iostream>
#include <vector>
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

using namespace std;

void f(int param)
{                              // param：形参
    int local_var = param;     // 普通局部变量
    static int static_var = 0; // 局部静态变量

    local_var++;
    static_var++;

        cout << "形参param=" << param
         << " 局部变量local_var=" << local_var
         << " 局部静态static_var=" << static_var << endl;
}

int main()
{
    f(10);
    f(20);
    f(30);
    return 0;
}