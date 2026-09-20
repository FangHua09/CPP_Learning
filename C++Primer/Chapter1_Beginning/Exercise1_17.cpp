/*
# 1.4.4 节练习解答

>
> 本节参考程序（统计连续重复数字出现次数）
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
1 2 2 3 3 4 4 4 5^Z
1出现次数是： 1
2出现次数是： 2
3出现次数是： 2
4出现次数是： 3
5出现次数是： 1
*/
