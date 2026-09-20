/*
题目描述
重写 1.6 节的书店程序，使用一个 vector 保存交易记录，使用不同算法完成处理。使用 sort 和 10.3.1 节中的 compareIsbn 函数来排序交易记录，然后使用 find 和 accumulate 求和。
知识点
自定义Sales_data类存储 ISBN、销量、销售额，重载+运算符支持累加。
compareIsbn 作为排序谓词，按 ISBN 字典序排序交易记录。
排序后相同 ISBN 的记录连续排列，用find_if定位每个 ISBN 的区间，accumulate累加该区间的总销售额。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

struct Sales_data
{
    string isbn() const { return bookNo; }
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// 按ISBN比较的谓词
bool compareIsbn(const Sales_data &a, const Sales_data &b)
{
    return a.isbn() < b.isbn();
}

// 重载+运算符，供accumulate累加
Sales_data operator+(const Sales_data &a, const Sales_data &b)
{
    Sales_data res;
    res.bookNo = a.bookNo;
    res.units_sold = a.units_sold + b.units_sold;
    res.revenue = a.revenue + b.revenue;
    return res;
}

int main(int argc, char const *argv[])
{
    vector<Sales_data> sales = {
        {"001", 2, 20.0},
        {"002", 1, 15.0},
        {"001", 3, 30.0},
        {"003", 5, 50.0},
        {"002", 2, 30.0}};

    sort(sales.begin(), sales.end(), compareIsbn);

    // 遍历统计每个ISBN的总和
    auto it = sales.begin();

    while (it != sales.end())
    {
        string curr_isbn = it->isbn();
        auto end_it = find_if(it, sales.end(), [&curr_isbn](const Sales_data &sale) -> bool
                              { return sale.isbn() != curr_isbn; });

        Sales_data total = accumulate(it, end_it, Sales_data{curr_isbn, 0, 0.0});
        /*
        001 销量：5 销售额：50
002 销量：3 销售额：45
003 销量：5 销售额：50
        */
        cout << total.isbn() << " 销量：" << total.units_sold
             << " 销售额：" << total.revenue << endl;
        it = end_it;
    }

    return 0;
}
