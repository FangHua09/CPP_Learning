// 练习 1.13：用 for 循环重做 1.4.1 的 3 道题
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
    //练习 1.9：50~100 整数相加（for 版本）
    int ans1 = 0;
    for (int i = 50; i <= 100; ++i) {
        ans1 += i;
    }
    std::cout << ans1 << '\n';

    // 练习 1.10：输出 10 到 0 递减（for 版本）
    for (int i = 10; i >= 0; i--)
    {
        std::cout << i << '\n';
    }

    // 3）练习 1.11：输出两个数区间内所有整数（for 版本）
    int a = 0, b = 10;
    for (int i = a; i <= b; ++i) {
        std::cout << i << '\n';
    }
    std::cout << '\n';  
    return 0;
}