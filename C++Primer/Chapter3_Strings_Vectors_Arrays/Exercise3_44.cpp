// 使用**类型别名**改写上面程序。
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
    using int_array = int[4]; // 类型别名

    for (int_array &i : ia)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    cout << "---------" << endl;

    // 版本2：下标
    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------" << endl;

    for (int_array *i = ia; i != ia + 3; i++)
    {
        for (int *j = *i; j != *i + 4; j++)
        {
            cout << *j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
