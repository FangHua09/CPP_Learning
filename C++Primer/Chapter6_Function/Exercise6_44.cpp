/*
题目：将 6.2.2 节（第 189 页）的 isShorter 函数改写成内联函数。
原版 isShorter
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
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

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}