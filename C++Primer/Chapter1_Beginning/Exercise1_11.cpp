// 练习 1.11：输入两个整数，打印区间内所有整数
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
    int a, b;
    std::cin >> a >> b;
    while (a <= b)
    {
        std::cout << a << '\n';
        a++;
    }
    
    return 0;
}
