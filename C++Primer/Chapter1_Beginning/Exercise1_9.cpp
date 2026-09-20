// 练习 1.9：while 循环求 50~100 整数和
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
    // 练习 1.9：while 循环求 50~100 整数和
    int num = 50;
    int sum = 0;
    while(num <= 100) {
        sum += num;
        num++;
    }
    std::cout << sum << '\n';
    return 0;
}
