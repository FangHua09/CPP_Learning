// **题目**：借助网站上的 Sales_item.h 头文件，编译并运行本节给出的书店程序。
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
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item total, trans;
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total.isbn() << "的报告下 ： " << total << '\n';
                total = trans;
            }
        }
        std::cout << total.isbn() << "的报告如下 ： " << total << '\n';
    }
    else
    {
        std::cerr << "没有输入 ！" << '\n';
    }
    return 0;
}
