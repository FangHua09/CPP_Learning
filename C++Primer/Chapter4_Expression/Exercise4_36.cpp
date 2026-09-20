/*
**【题目描述】**：假设`i`是`int`类型，`d`是`double`类型，书写表达式`i *= d`使其执行**整数类型乘法**，而不是浮点数乘法。
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

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 2;
    double d = 0.2;
    i *= static_cast<int>(d);
    return 0;
}
