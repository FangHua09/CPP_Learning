// **题目描述**：改写上题的程序，不过这次读入的是字符串。

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
    // **题目描述**：改写上题的程序，不过这次读入的是字符串。
    
    vector<string> v;
    string s;
    while(cin >> s) v.push_back(s);

    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    
    return 0;
}
