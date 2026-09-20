// 重写练习 10.12 的程序，在对 sort 的调用中使用 lambda 来代替函数 `compareIsbn`。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Sales_data
{
    string isbn() const { return bookNo; }
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    vector<Sales_data> sales_vec = {
        {"978-7-111-12345-6", 10, 59.8},
        {"978-7-111-00001-2", 5, 39.9},
        {"978-7-111-56789-0", 8, 89.0}};

    // 直接在sort中使用lambda，替代单独的compareIsbn函数
    sort(sales_vec.begin(), sales_vec.end(), [](const Sales_data &s1, const Sales_data &s2) -> bool
         { return s1.isbn() < s2.isbn(); });

    cout << "按ISBN排序后：" << endl;
    for (const auto &item : sales_vec)
        cout << item.isbn() << endl;

    return 0;
}