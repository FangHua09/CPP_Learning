/*
【题目描述】：本节程序用前置递增 / 递减，解释为什么用前置而不用后置。如果改用后置版本需要做哪些改动？用后置重写程序。
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
    vector<int> v(10);
    vector<int>::size_type cnt = v.size();

    for (vector<int>::size_type ix = 0; ix != v.size(); ++ix, --cnt)
    {
        v[ix] = cnt;
    }

    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    
    return 0;
}
