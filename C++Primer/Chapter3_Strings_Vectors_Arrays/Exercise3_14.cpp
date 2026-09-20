// **题目描述**：编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。
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
    // **题目描述**：编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。
    int digit = 0;
    vector<int> v;
    while(cin >> digit) v.push_back(digit);
    for (auto &&i : v)
    {
        cout << i;
    }
    

    return 0;
}
