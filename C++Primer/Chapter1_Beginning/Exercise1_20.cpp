/*
**题目**：在网站上，第 1 章的代码目录中包含了头文件 Sales_item.h。
将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
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
    Sales_item item;
    while (std::cin >> item)
    {
        std::cout << item << '\n' << '\n';
    }
    
    return 0;
}
