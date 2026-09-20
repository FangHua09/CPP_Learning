/*
编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 简化的Sales_data类
struct Sales_data
{
    string isbn() const { return bookNo; }
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// 按ISBN字典序比较的谓词
bool compareIsbn(const Sales_data &a, const Sales_data &b)
{
    return a.isbn() < b.isbn();
}

int main(int argc, char const *argv[])
{
    vector<Sales_data> sales_vec = {
        {"978-7-111-12345-6", 10, 59.8},
        {"978-7-111-00001-2", 5, 39.9},
        {"978-7-111-56789-0", 8, 89.0}};

    sort(sales_vec.begin(), sales_vec.end(), compareIsbn);

    cout << "按ISBN排序后：" << endl;
    for (const auto &item : sales_vec)
        cout << item.isbn() << endl;
    return 0;
}
