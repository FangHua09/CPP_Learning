//  和用户交互的阶乘函数，main 调用
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

int fact_interact (int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact_interact(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fact_interact(n) << '\n';
    return 0;
}
