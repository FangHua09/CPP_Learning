/*
多维数组：`int ia[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};`
3 个版本输出全部元素；**禁止 auto、decltype、类型别名**，写死原始类型。

- 版本 1：范围 for 循环
- 版本 2：普通 for + 下标
- 版本 3：普通 for + 指针
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
    多维数组：`int ia[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};`
3 个版本输出全部元素；**禁止 auto、decltype、类型别名**，写死原始类型。

- 版本 1：范围 for 循环
- 版本 2：普通 for + 下标
- 版本 3：普通 for + 指针
    */
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    for (int (&i)[4] : ia)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }

    cout << "---------" << endl;

    for (int (*i)[4] = ia; i != (ia + 3); i++)
    {
        for (int *j = *i; j != (*i + 4); j++)
        {
            cout << *j << ' ';
        }
        cout << '\n';
    }

    cout << "---------" << endl;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << ia[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
