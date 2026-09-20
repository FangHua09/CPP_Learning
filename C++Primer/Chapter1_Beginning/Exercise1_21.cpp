// **题目**：编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出它们的和。

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
    Sales_item item1;
    Sales_item item2;
    std::cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << '\n';
    }
    else
    {
        std::cout << "二者序列号不相同" << '\n';
    }
    return 0;
}
/*

0-201-70353-X 2 24.99
0-201-70353-X 3 24.99
0-201-70353-X 5 124.95 24.99
*/