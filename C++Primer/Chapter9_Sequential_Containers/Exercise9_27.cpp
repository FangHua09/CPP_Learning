// 编写程序，查找并删除 `forward_list<int>` 中的奇数元素。

/*
forward_list 是单向链表，没有普通的 erase(it) 接口，只能通过 erase_after(prev) 删除 prev 迭代器之后的元素。
删除元素必须维护前驱迭代器 prev，初始值为 before_begin()（首元素之前的占位位置）。
erase_after(prev) 返回被删除元素的下一个元素迭代器，直接赋值给 curr 继续遍历。
不删除元素时，prev 和 curr 同步向后移动。
*/
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
    forward_list<int> flst{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 查找并删除 `forward_list<int>` 中的奇数元素。
    auto pre = flst.before_begin();
    auto cur = flst.begin();

    while (cur != flst.end())
    {
        if (*cur % 2 == 1)
        {
            cur = flst.erase_after(pre);
        }
        else
        {
            pre = cur;
            ++cur;
        }
    }

    for (auto x : flst)
        cout << x << " ";
    cout << endl;

    return 0;
}
