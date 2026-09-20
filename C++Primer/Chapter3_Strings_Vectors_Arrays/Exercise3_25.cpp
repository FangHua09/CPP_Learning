/*
**题目描述**：3.3.3 节（第 93 页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。
原题逻辑：统计 0‑9,10‑19,…,90‑99,100，共 11 个分数段的人数
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
    vector<int> v(11); // index 0-10
    int i;
    auto it = v.begin();
    while (cin >> i)
    {
        (*(it + i / 10))++;
    }

    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}
