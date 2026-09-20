/*
**有连续重复的单词是以大写字母开头时，才 break 退出**；小写开头的连续重复忽略，继续读取。
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
    string pre, cur;
    bool flag = false;
    if (cin >> pre)
    {
        while (cin >> cur)
        {
            if (pre == cur)
            {
                if (isupper(pre[0]))
                {
                    cout << pre << "两个相同，退出" << '\n';
                    flag = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                pre = cur;
            }
        }
        // 读到末尾了
        if (!flag)
        {
            cout << "没有连续的两个一样的单词" << '\n';
        }
    }
    return 0;
}
