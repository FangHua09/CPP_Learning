/*
第 316 页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。
第 316 页原程序（vector 版本）：
auto iter = vi.begin();
while (iter != vi.end()) {
    if (*iter % 2) {
        iter = vi.insert(iter, *iter);
        iter += 2;
    } else {
        iter = vi.erase(iter);
    }
}
解答
不能用于list/forward_list的原因：
list迭代器是双向迭代器，不支持iter += 2这种随机访问加法运算，只能使用++iter；
forward_list没有普通insert()、erase()成员函数，只能使用insert_after()、erase_after()，需要维护前驱迭代器，不能直接操作当前元素迭代器。
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
    // list<int> lst{0,1,2,3,4,5,6,7};
    // // 倍增奇数，删除偶数。list版本
    // auto it = lst.begin();

    // while(it != lst.end()) {
    //     if (*it % 2) {
    //         // 倍增奇数
    //         it = lst.insert(it, *it); // 此时it指向新插入的元素（即原来的元素之前）
    //         ++it;
    //         ++it;// 让it向后移动两次，因为不支持+=操作
    //     } else {
    //         // 删除偶数
    //         it = lst.erase(it);
    //     }
    // }
    // for(auto x : lst) cout << x << " ";

    // 倍增奇数，删除偶数。forward_list版本
    forward_list<int> lst{0, 1, 2, 3, 4, 5, 6, 7};
    auto pre = lst.before_begin(); // 维护一个前驱指针
    auto cur = lst.begin();        // 当前指针

    while (cur != lst.end())
    {
        if (*cur % 2 == 1)
        {
            // 复制奇数
            pre = lst.insert_after(pre, *cur); // pre要去做接收
            pre = cur; // pre又步进
            ++cur; //cur只需要做一次加加，因为本来就在老位置，只是前面多了个成员
            /*
辅助理解
1 2 3 4 5 
pre之后插入999 （pre仍然没变）
return : 999
cur : 1
999 1 2 3 4 5 
            */
        }
        else
        {
            // 删除偶数
            cur = lst.erase_after(pre); // 此时返回原来cur的下一个合法位置，让cur接收，因为cur已经失效
        }
    }

     for(auto x : lst) cout << x << " ";

    return 0;
}
