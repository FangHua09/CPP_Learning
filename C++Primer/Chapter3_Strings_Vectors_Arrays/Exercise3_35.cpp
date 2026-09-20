// 利用指针将数组中的元素置为 0。
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


int main()
{
    constexpr size_t sz = 10;
    int a[sz] = {1,2,3,4,5,6,7,8,9,10};

    for (auto it = begin(a); it != end(a); it++)
    {
        *it = 0;
    }
    

    //输出验证
    for (auto x : a)
        cout << x << " ";
    return 0;
}
