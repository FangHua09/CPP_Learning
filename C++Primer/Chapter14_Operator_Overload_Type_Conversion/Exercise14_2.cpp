/*
 *练习 14.2：Sales_data 重载输入、输出、加法、复合赋值运算符
 Sales_data 类，成员：bookNo，units_sold，revenue
 */

#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    // 复合赋值运算符
    Sales_data &operator+=(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
};

// 输入运算符
istream &operator>>(istream &is, Sales_data &item)
{
    double prices;
    is >> item.bookNo >> item.units_sold >> prices;
    if (is)
    {
        item.revenue = prices * item.units_sold;
    }
    return is;
}

// 输出运算符
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}

// 加法运算符 对称就放非成员
Sales_data operator+(const Sales_data &item1, const Sales_data &item2)
{
    if (item1.bookNo == item2.bookNo)
    {
        Sales_data total;
        total.bookNo = item1.bookNo;
        total.units_sold = item1.units_sold + item2.units_sold;
        total.revenue = item1.revenue + item2.revenue;
        return total;
    }
    else
    {
        cout << "两本书的书号不一样" << '\n';
        return Sales_data();
    }
}