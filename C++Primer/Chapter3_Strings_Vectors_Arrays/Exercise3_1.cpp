/*
**题目描述**：使用恰当的 using 声明重做 1.4.1 节（第 11 页）和 2.6.2 节（第 67 页）的练习。
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif

#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data item1, item2;
    double price1, price2;
    cin >> item1.bookNo >> item1.units_sold >> price1;
    item1.revenue = item1.units_sold * price1;

    cin >> item2.bookNo >> item2.units_sold >> price2;
    item2.revenue = item2.units_sold * price2;

    if (item1.bookNo == item2.bookNo)
    {
        unsigned total_sold = item1.units_sold + item2.units_sold;
        double total_rev = item1.revenue + item2.revenue;
        cout << item1.bookNo << " " << total_sold << " " << total_rev << endl;
    }
    else
    {
        cerr << "ISBN不相同" << endl;
        return -1;
    }
    return 0;
}


*/