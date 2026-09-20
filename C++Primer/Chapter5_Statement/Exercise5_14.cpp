/*
需求：读取若干 string，查找连续重复单词；记录最大连续次数与对应单词；没有连续重复则输出提示。
样例输入：how now now now brown cow cow，输出：now 连续出现了3次
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
    int cnt = 1, maxCnt = 0;
    string cur, pre, max;

    if (cin >> pre)
    {
        while (cin >> cur)
        {
            if (cur == pre)
            {
                cnt++;
            }
            else
            {
                if (cnt > maxCnt)
                {
                    max = pre;
                    maxCnt = cnt;
                }
                pre = cur;
                cnt = 1;
            }
        }

        if (maxCnt > 1)
            cout << max << " " << maxCnt << '\n';
        else
            cout << "没有连续出现的单词" << '\n';
    }

    return 0;
}
