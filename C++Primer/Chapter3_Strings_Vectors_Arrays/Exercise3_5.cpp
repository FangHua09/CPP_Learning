/*
**题目描述**：编写一段程序从标准输入中读入多个字符串并将它们连接在一起，
输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。
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
    string ans;
    string s;

    if (cin >> s)
    {
        ans += s;
        while (cin >> s)
        {
            ans += " ";
            ans += s;
        }
        cout << ans << endl;
    }
    else
    {
        cerr << "请输入字符串" << endl;
        return -1;
    }

    return 0;
}
