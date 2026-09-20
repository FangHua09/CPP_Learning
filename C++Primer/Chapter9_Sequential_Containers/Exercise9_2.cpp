// 定义一个 `list` 对象，其元素类型是 `int` 的 `deque`。
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
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
    // list容器，每个元素是 deque<int>
    list<deque<int>> ld;

    ld = {{1}, {2, 3}, {1, 2, 3}};

    for (auto &&i : ld)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    /*
1
2 3
1 2 3
    */

    return 0;
}
