// 编写函数输出实参的绝对值
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

void getAbs(int n)
{
    if (n < 0)
    {
        cout << -n << '\n';
        return;
    }
    cout << n << '\n';
}

int main()
{
    getAbs(-10); // 输出10
    getAbs(7);   // 输出7
    return 0;
}