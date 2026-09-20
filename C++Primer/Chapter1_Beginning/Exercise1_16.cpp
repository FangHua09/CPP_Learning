// # 练习 1.16

// 题目：编写程序，从 `cin` 读取一组数，输出其和。
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
    int sum = 0;
    int i;
    while(std::cin >> i) {
        sum += i;
    }
    std::cout << sum << '\n';
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10^Z
// 55