/*
 *知识点：输出运算符 operator<<
 规则：
 必须是非成员函数；第一个形参是ostream&，第二个是const类引用；返回ostream&。
 尽量不要在<<里输出换行，交给用户控制。
 如果需要访问私有成员，要声明为friend友元。
 练习 14.6：Sales_data 输出运算符
 */

#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    friend ostream &operator<<(ostream &os, Sales_data &item);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

ostream &operator<<(ostream &os, Sales_data &item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}