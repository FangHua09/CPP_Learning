// 使用`auto`关键字再次改写。
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
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    for (auto &&i : ia)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    cout << "---------" << endl;

    for (auto i = 0; i != 3; ++i)
    {
        for (auto j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------" << endl;

    // 此时这里i是指向长度为四的整型数组的指针
    for (auto i = ia; i != ia + 3; i++)
    {
        // 此时这里j是长度为四的整型数组（首元素的指针）
        for (auto j = *i; j != *i + 4; j++)
        {
            cout << *j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
