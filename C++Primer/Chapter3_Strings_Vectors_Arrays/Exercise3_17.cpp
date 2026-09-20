/*
**题目描述**：从 cin 读入一组词并把它们存入一个 vector 对象，
然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。
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
    /*
    **题目描述**：从 cin 读入一组词并把它们存入一个 vector 对象
    ，然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。
    */
    vector<string> v;
    string s;
    while (cin >> s)
        v.push_back(s);

    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            j = toupper(j);
        }
    }

    for (auto &&i : v)
    {
        cout << i << '\n';
    }
    

    return 0;
}
