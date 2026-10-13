/*
 *练习 16.49：分析每一次调用（模板重载决议）
 规则：模板重载时，更特例化的版本优先匹配。

 g 的两个模板：
 template <typename T> void g(T);    // 版本1：接受任意类型（通用）
 template <typename T> void g(T*);   // 版本2：接受指针类型（更特例）
 
 g(42);
 实参是int，不是指针。只能匹配 g (T)，T=int。
 g(p);
 p 是 int* 指针。g(T*) 是更特例版本，优先匹配；T=int。调用g<int*>(int*)❌→ 匹配g<int>(int*)。
 g(ci);
 ci 是const int，不是指针。匹配g(T)，T=const int。
 g(p2);
 p2 是const int*指针。优先匹配g(T*)，T=const int。

 f 的两个模板：
 template <typename T> void f(T);         //版本A：通用
 template <typename T> void f(const T*);  //版本B：const T* 指针
 
 f(42);
 int 非指针，匹配f(T)，T=int。
 f(p);
 p 是int *。
 版本 A：T 推导为int*；
 版本 B：需要const T*，int*可以隐式转换到const int*；
 但是版本 A 是精确匹配，版本 B 需要转换。所以匹配 f(T)，T=int*。
 f(ci);
 ci 是 const int，非指针，匹配f(T)，T=const int。
 f(p2);
 p2 是const int *。版本 B f(const T*) 精确匹配，T=int。
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

template <typename T>
void g(T); // 版本1：接受任意类型（通用）
template <typename T>
void g(T *); // 版本2：接受指针类型（更特例）

template <typename T>
void f(T); // 版本A：通用
template <typename T>
void f(const T *); // 版本B：const T* 指针

int main(int argc, char const *argv[])
{

    return 0;
}
