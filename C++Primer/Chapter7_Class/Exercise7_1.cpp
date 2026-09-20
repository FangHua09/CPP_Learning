// **题目描述**：使用 2.6.1 节练习定义的`Sales_data`类，为 1.6 节的交易处理程序编写新版本。
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

#include <string>
struct Sales_data
{
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
            if (trans.bookNo == total.bookNo)
            {
                // ISBN相同，累加
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
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

/*
0-201-70353-X 6 49.98
^Z
0-201-70354-X 3 45
*/