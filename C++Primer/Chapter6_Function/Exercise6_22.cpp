/*
题目描述：编写一个函数，令其交换两个 int 指针。
交换指针本身的值（两个指针变量存的地址互换），不是交换指针指向的 int 数值。要修改指针变量本身，形参需要是指针的指针 int**，或者指针的引用 int*&。

交换前：p=0xc9e95ffa5c *p=100  q=0xc9e95ffa58 *q=200
交换后：p=0xc9e95ffa5c *p=100  q=0xc9e95ffa58 *q=200
(base) PS C:\Users\13075\CLionPcd "c:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function\"; if (!(Test-Path output)) { mkdir output }; g++ -g Exercise6_22.cpp -o output/Exercise6_22.exe; ./output/Exercise6_22.exe
交换前：p=0x40047ffbcc *p=100  q=0x40047ffbc8 *q=200
交换后：p=0x40047ffbc8 *p=200  q=0x40047ffbcc *q=100
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

void swap_ptr(int *&a, int *&b) {
    int *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 100, y = 200;
    int *p = &x;
    int *q = &y;

    cout << "交换前：p=" << p << " *p=" << *p << "  q=" << q << " *q=" << *q << endl;
    swap_ptr(p, q);
    cout << "交换后：p=" << p << " *p=" << *p << "  q=" << q << " *q=" << *q << endl;
    return 0;
}