//**题目描述**：请使用迭代器重做 3.3.3 节的最后一个练习（练习 3.20：输出相邻元素和；再输出第 1 个 + 最后 1 个、第 2 个 + 倒数第 2 个……）。
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
    int i;
    vector<int> v;
    while (cin >> i)
        v.push_back(i);

    for (auto i = v.begin(); (i + 1) != v.end(); i++)
    {
        cout << *i + *(i + 1) << " ";
    }

    cout << '\n';

    for (auto i = v.begin(), j = v.end() - 1; i < j; ++i, --j)
    {
        cout << *i + *j << " ";
    }
    cout << '\n';

    return 0;
}
