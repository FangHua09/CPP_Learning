// 12 把整数从 **‑100 到 100** 的全部数字累加求和。

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
    // 把整数从 **‑100 到 100** 的全部数字累加求和。
    int ans = 0;
    for (int i = -100; i <= 100; ++i) {
        ans += i;
    }

    std::cout << ans << '\n';
    return 0;
}