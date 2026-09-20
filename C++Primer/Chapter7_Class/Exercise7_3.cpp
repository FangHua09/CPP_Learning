// 修改 7.1.1 交易处理程序，使用上面的成员函数`isbn()`、`combine()`。
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
    // 题目描述：向 Sales_data 类添加combine成员函数与isbn成员函数。
    Sales_data &combine(const Sales_data &s)
    {
        units_sold += s.units_sold;
        revenue += s.revenue;
        return *this;
    }

    string isbn() const
    {
        return bookNo;
    }

    std::string bookNo;      // isbn
    unsigned units_sold = 0; // 售出数量
    double revenue = 0.0;    // 收入
};

int main(int argc, char const *argv[])
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (trans.isbn() == total.isbn())
            {
                total.combine(trans);
            }
            else
            {
                // ISBN不同，打印上一组总和
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;
            }
        }
        // 打印最后一本
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << std::endl;
    }
    else
    {
        cerr << "没有数据" << endl;
    }
    return 0;
}
