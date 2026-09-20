// > 需求：遍历`vector<int>`，**奇数翻倍**，使用条件运算符`?:`。

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
    vector<int> vec{1,2,3,4,5,6,7,8};
    for (auto &&i : vec)
    {
        i = ((i % 2 == 1) ? i*2 : i);
    }

    for (auto v : vec)
        cout << v << " ";
    
    return 0;
}
