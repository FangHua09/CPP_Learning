// do‑while，反复输入两个 string，输出较短的那个
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
    string s1, s2;
    char ch;
    do
    {
        cout << "请输入两个字符串：" << endl;
        cin >> s1 >> s2;
        if (s1.size() <= s2.size())
            cout << "较短字符串：" << s1 << endl;
        else
            cout << "较短字符串：" << s2 << endl;

        cout << "是否继续？输入y继续，其他退出：";
        cin >> ch;
    } while (ch != 'n');

    return 0;
}
