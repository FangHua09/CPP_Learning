// 定义含有 10 个 int 的数组，每个元素值等于其下标值。
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
    int a[10];
    for (size_t i = 0; i < 10; i++)
    {
        a[i] = i;
    }

    for (auto &&i : a)
    {
        cout << i << " ";
    }
    
    
    return 0;
}
