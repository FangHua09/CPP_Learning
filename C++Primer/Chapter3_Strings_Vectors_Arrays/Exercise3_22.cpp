/*
> **题目描述**：修改之前那个输出 text 第一段的程序，
首先把 text 的第一段全都改成大写形式，然后再输出它。

>
> 原题背景：`vector<string> text`保存文章，
每一个 string 是一行；空字符串代表段落结束；
第一段就是直到遇到空字符串之前的内容。
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
    vector<string> v;
    string s;
    while (getline(cin, s))
        v.push_back(s);

    for (auto i = v.begin(); i != v.end(); i++)
    {
        for (auto &&j : *i)
        {
            j = toupper(j);
        }
    }

    // 输出第一段
    for (auto it = v.begin(); it != v.end() && !it->empty(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
