/*
实现 3 个非成员函数：
read：从流读取数据到Sales_data对象；修改对象，参数用普通引用，返回istream&
print：输出Sales_data；不修改对象，参数const引用，返回ostream&
add：求两个Sales_data相加，返回新Sales_data对象
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

struct Sales_data
{
    // 不属于非成员函数（接口函数）
    // // print函数
    // ostream &print(ostream &os, const Sales_data &s);

    // // read函数
    // istream &read(istream &is, Sales_data &s);

    // add
    Sales_data add(const Sales_data &s1, const Sales_data &s2);

    // 题目描述：向 Sales_data 类添加combine成员函数与isbn成员函数。
    Sales_data &combine(const Sales_data &s);

    string isbn() const
    {
        return bookNo;
    }

    std::string bookNo;      // isbn
    unsigned units_sold = 0; // 售出数量
    double revenue = 0.0;    // 收入
};

// print函数
ostream &print(ostream &os, const Sales_data &s)
{
    os << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << (s.revenue * 1.0) / s.units_sold;
    return os;
}

// read函数
istream &read(istream &is, Sales_data &s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return is;
}

// add
Sales_data Sales_data::add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data sum;
    sum = s1;
    sum.combine(s2);
    return sum; // 值拷贝
}

// 类外定义combine函数
Sales_data &Sales_data::combine(const Sales_data &s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}