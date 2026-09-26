/*
 *练习 14.20：Sales_data 定义 + 和 +=（教材标准写法）
 规则：复合赋值 += 是成员函数；普通加法 + 是非成员，基于+=实现。
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

struct Sales_data
{
    Sales_data &operator+=(const Sales_data &rhs);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    if (bookNo != rhs.bookNo)
        throw runtime_error("different bookNo");
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 普通加法：创建副本，调用 +=
Sales_data operator+(Sales_data lhs, const Sales_data &rhs)
{
    // 不需要创建友元 调用+= 以及重复利用已经拷贝的第一个参数的副本
    lhs += rhs;
    return lhs;
}

