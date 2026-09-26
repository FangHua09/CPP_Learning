/*
 *C++ Primer 14.3 节练习 14.13 ~ 14.15
 练习 14.13：Sales_data 还应该支持哪些算术运算符
 Sales_data 代表一本书的销售记录：bookNo 书号，units_sold销量，revenue总收入。业务含义：两个 Sales_data 相加，代表同一种书籍的销售记录合并（销量累加、收入累加）。
 分析各个算术运算符
 +、+= ✅ 有意义：合并同书籍销售数据，我们已经实现。
 -、-= ✅ 有意义：代表销售退回、减去某条销售记录；同书号才能相减。
 *、/、% ❌ 没有业务含义：两条销售记录相乘 / 除没有现实意义，不需要实现。
 结论：Sales_data 适合增加 - 和 -=。
 */

#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    friend ostream &operator<<(ostream &os, const Sales_data &item);
    friend istream &operator>>(istream &is, Sales_data &item);

    Sales_data &operator+=(const Sales_data &rhs)
    {

        if (bookNo == rhs.bookNo)
        {
            units_sold += rhs.units_sold;
            revenue += rhs.revenue;
        }
        return *this;
    }
    Sales_data &operator-=(const Sales_data &rhs)
    {
        if (bookNo == rhs.bookNo)
        {
            units_sold -= rhs.units_sold;
            revenue -= rhs.revenue;
        }
        return *this;
    }

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}

istream &operator>>(istream &is, Sales_data &item)
{
    double prices;
    is >> item.bookNo >> item.units_sold >> prices;
    if (is)
    {
        item.revenue = prices * item.units_sold;
    }
    else
    {
        item = Sales_data();
    }
    return is;
}

Sales_data operator+(Sales_data item1, const Sales_data &item2)
{
    if (item1.bookNo == item2.bookNo)
    {
        item1 += item2;
        return item1;
    }
    else
    {
        cerr << "isbn不同！" << endl;
        return Sales_data();
    }
}
Sales_data operator-(Sales_data item1, const Sales_data &item2)
{
    if (item1.bookNo == item2.bookNo)
    {
        item1 -= item2;
        return item1;
    }
    else
    {
        cerr << "isbn不同！" << endl;
        return Sales_data();
    }
}
