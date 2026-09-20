// 用整型数组初始化一个`vector`对象。
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
    int a[10] = {1, 2, 3, 4, 5, 6};
    vector<int> v(begin(a), end(a));

    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}
