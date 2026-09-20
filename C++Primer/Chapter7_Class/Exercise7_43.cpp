/*
NoDefault：只有接收int的构造函数，没有默认构造函数。类C含有NoDefault类型成员；需要定义 C 的默认构造函数。
关键点：NoDefault没有默认构造，C 的默认构造函数必须在初始化列表显式初始化这个成员，不能交给编译器。
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

class NoDefault
{
public:
    NoDefault(int n) {}
    // 没有默认构造
};

class C
{
    public:
    NoDefault nd; // 有一个nodefalut成员

    //尝试定义C的默认构造函数
    //C(){} // 类 "NoDefault" 不存在默认构造函数
    C() : nd(0){} 
};