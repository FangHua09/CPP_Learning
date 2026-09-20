/*
**题目描述**：使用你自己的 Sales_data 类重写 1.5.1 节（第 20 页）、1.5.2 节（第 21 页）和 1.6 节（第 22 页）的练习。眼下先把 Sales_data 类的定义和 main 函数放在同一个文件里。
*/

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

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
};

int main(int argc, char const *argv[])
{
    // 要求一 ：
    Sales_data item;
    while (std::cin >> item.bookNo >> item.price >> item.units_sold >> item.revenue)
    {
        std::cout << item.bookNo << " " << item.price << "  " << item.revenue << "  " << item.units_sold << '\n';
    }

    // 要求三 ：
    Sales_data item1, item2;

    // 读入二者的信息
    std::cin >> item1.bookNo >> item1.units_sold >> item1.price;
    std::cin >> item2.bookNo >> item2.units_sold >> item2.price;

    // 对比
    Sales_data total;
    if (item1.bookNo == item2.bookNo)
    {
        total.bookNo = item1.bookNo;
        total.price = item1.price;
        total.revenue = item1.revenue;
        total.units_sold = total.units_sold;

        std::cout << total.bookNo << " " << total.price << " " << total.revenue << " " << total.units_sold << '\n';
    }
    else
    {
        std::cout << "二者书号不同！" << '\n';
    }
    return 0;
}
