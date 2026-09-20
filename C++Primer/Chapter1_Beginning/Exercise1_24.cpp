/*
编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。
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
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item curItem, item;
    if (std::cin >> curItem)
    {
        int cnt = 1;
        while (std::cin >> item)
        {
            if (item.isbn() == curItem.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout << curItem.isbn() << "出现的次数有 ： " << cnt << std::endl;
                cnt = 1;
                curItem = item;
            }
        }
        std::cout << curItem.isbn() << "出现的次数有 ： " << cnt << std::endl;
    }
    else
    {
        std::cout << "没有输入有效信息" << '\n';
        return -1;
    }
    return 0;
}
