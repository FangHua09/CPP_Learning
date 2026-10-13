/*
Exercise1_1
题目描述
解释为什么程序 1-7 的交换函数没有把形参 x 和 y 所对应的实参的值交换？如何修改代码，使实参的值得到交换？
程序 1-7（原题给出的错误代码）
void swap(int x,int y)
{
//交换整数x和y
int temp=x;
x=y;
y=temp;
}
知识点
C++值传递：函数调用时，形参是实参的独立副本，函数内部修改副本，不会影响外部原始实参变量。
想要修改外部变量，需要引用传递（&），引用是实参的别名，操作引用等价操作原变量；也可以使用指针。
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
void f1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void f2(int *a, int *b)
{
    // 交换值
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void f3(int *a, int *b)
{
    // 交换地址错误写法
    /*
    C++ 中函数参数默认是值传递。
    指针本身也是一个变量，存的是地址；当指针作为形参时，传递的是地址值的拷贝。
    f3(int *a, int *b)：a 和 b 是函数内部局部指针变量，只是复制了实参传过来的地址。
    main:
    int a=10  地址0x100
    int b=20  地址0x200
    调用 f3(&a,&b)
    f3局部指针：
    a(副本) = 0x100
    b(副本) = 0x200
    交换局部指针a,b：
    a(副本)=0x200
    b(副本)=0x100
    函数结束，局部指针销毁。main里面0x100和0x200内存的值依旧是10、20！
    */
    int *temp = a;
    a = b;
    b = temp;
}
void f4(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[])
{
    int a = 10, b = 20;
    f1(a, b);
    cout << a << " " << b << '\n';
    f2(&a, &b);
    cout << a << " " << b << '\n';
    f3(&a, &b);
    cout << a << " " << b << '\n'; // 转换失败
    int *p = &a, *q = &b;
    f4(&p, &q);
    cout << *p << " " << *q << '\n';
    return 0;
}