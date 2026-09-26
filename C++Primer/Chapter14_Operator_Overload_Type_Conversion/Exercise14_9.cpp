/*
 *知识点：输入运算符 operator>>
 核心规则：
 必须是非成员函数，第一个参数istream&，第二个是普通引用（不能 const，要修改对象），返回istream&。
 输入失败时，要把对象重置为默认状态，并且设置流的错误标志。
 输入运算符内部不要输出提示信息（和输出运算符区分）。
 练习 14.9：Sales_data 输入运算符
 */

#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    friend ostream &operator<<(ostream &os, Sales_data &item);
    friend istream &operator>>(istream &is, Sales_data &item);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

ostream &operator<<(ostream &os, Sales_data &item)
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