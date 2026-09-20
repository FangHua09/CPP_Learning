// 将整数`vector`拷贝给整型数组。
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
    vector<int> v{10,20,30,40,50};
    constexpr size_t sz = 5;
    int a[sz];

    auto it = v.begin();
    for (size_t i = 0; i < sz; ++i, ++it)
    {
        a[i] = *it;
    }
    
    return 0;
}
