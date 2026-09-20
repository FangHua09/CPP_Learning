// 编写 fact 阶乘函数
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

using namespace std;

int fact (int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

int main(int argc, char const *argv[])
{
    cout << fact(5) << '\n';
    return 0;
}
