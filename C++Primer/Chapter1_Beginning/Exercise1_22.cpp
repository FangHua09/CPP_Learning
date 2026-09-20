// **题目**：编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。
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
    //**题目**：编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。
    Sales_item curItem, item;
    if (std::cin >> curItem)
    {
        while (std::cin >> item)
        {
            if (curItem.isbn() == item.isbn())
            {
                curItem += item;
            }
            else
            {
                std::cout << curItem << '\n';
                // 记得更新curItem
                curItem = item;
            }
        }
        std::cout << curItem << '\n';
    }
    return 0;
}

/*
0-201-70353-X 2 24.99
0-201-70353-X 3 24.99
0-201-70353-X 5 24.99^Z
^Z
0-201-70353-X 10 249.9 24.99
*/