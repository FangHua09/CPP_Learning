/*
题目描述：参考本节介绍的几个 print 函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的 i 和 j：int i = 0, j[2] = { 0, 1 };
C++ 数组形参会退化为指针；几种常见 print 数组版本：值传递数组指针、数组大小显式传参、标准库 begin/end、数组引用形参。
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

// 版本1：传入数组首地址+数组大小
void print(const int *a, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << a[i] << ' ';
    }
}

// 版本2：传入首尾迭代器指针
void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << ' ';
    }
}

// 版本3：数组引用形参，限定数组大小
void print(const int (&a)[10])
{
    for (auto &&i : a)
    {
        cout << i << ' ';
    }
}

int main(int argc, char const *argv[])
{

    int i = 0;
    int j[2] = {0, 1};

    // i是单个int，包装成数组传入
    print(&i, 1);
    print(&i, &i + 1);

    // j是大小为2的数组
    print(j, 2);
    print(begin(j), end(j));
    //print(j); //限制了数组的大小，如果不是10则引用不了
    return 0;
}
