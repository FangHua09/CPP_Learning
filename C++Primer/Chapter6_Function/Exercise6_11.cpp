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

// 编写并验证 reset 函数，使其作用于引用类型参数。

void reset(int &n){
    n = 0;
}
int main(int argc, char const *argv[])
{
    int n = 999;
    reset(n);
    cout << n << '\n';
    return 0;
}
