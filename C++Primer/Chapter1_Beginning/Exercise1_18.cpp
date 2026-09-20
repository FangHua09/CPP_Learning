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

int main(int argc, char const *argv[])
{
    int curVal, val;
    if (std::cin >> curVal)
    {
        int cnt = 1; // 记录当前数字出现次数
        // 循环读入后续的数字
        while (std::cin >> val)
        {
            if (val == curVal)
            {
                cnt++;
            }
            else
            {
                std::cout << curVal << "出现次数是： " << cnt << "\n";
                // 记得更新curVal
                curVal = val;
                // 记得重置cnt
                cnt = 1;
            }
        }
        std::cout << curVal << "出现次数是： " << cnt << "\n";
    }
    return 0;
}

/*
编译运行上面这段程序做两组测试：

1. 全部相等输入：`7 7 7 7 7` → 输出一行 `7 occurs 5 times`
2. 无重复输入：`10 20 30 40` → 每个数字各输出一行，次数为 1。

> 
> 实操提示：Windows 输入完成按`Ctrl+Z`结束输入；Mac/Linux 按`Ctrl+D`。

*/