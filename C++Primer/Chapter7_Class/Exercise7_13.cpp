/*
使用 istream 构造函数重写交易处理程序。
原来用`read(cin,total)`，现在直接`Sales_data total(cin);`
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
// ✅前向声明
struct Sales_data;

// 非成员函数声明，写在结构体前面，依赖前向声明
ostream &print(ostream &os, const Sales_data &s);
istream &read(istream &is, Sales_data &s);

struct Sales_data
{
    // 不属于非成员函数（接口函数）
    // // print函数
    // ostream &print(ostream &os, const Sales_data &s);

    // // read函数
    // istream &read(istream &is, Sales_data &s);

    // 默认构造函数 （前提要为内置类型或者复合类型赋予初始值）
    Sales_data() = default;

    // 接收 ISBN，数量，单价
    Sales_data(const string &bookNo, unsigned units_sold, double price) : bookNo(bookNo), units_sold(units_sold), revenue(price * units_sold) {}

    // 只接收 ISBN
    Sales_data(const string &s) : bookNo(s) {}

    // 接收`std::istream&` inline
    Sales_data(istream &is)
    {
        // 复用read函数 但是声明先写上
        read(is, *this); // 把本对象传入
    }

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
    os << "书号： " << s.isbn() << " 售卖数量： " << s.units_sold << " 收入 ： " << s.revenue;
    if (s.units_sold != 0)
    {
        os << " 书籍单价： " << s.revenue / s.units_sold;
    }
    else
    {
        os << " " << "0";
    }
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

// 测试
// main：全部4个构造函数都使用
int main()
{
    Sales_data total(cin);
    if (cin) // 优先判断流是否读取成功，比判断isbn().empty()更严谨
    {
        Sales_data trans;
        while (read(cin, trans)) // 这里依然用read来读取下一条，不反复调用istream构造
        {
            if (trans.isbn() == total.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "没有读到有效数据" << endl;
    }

    return 0;
}