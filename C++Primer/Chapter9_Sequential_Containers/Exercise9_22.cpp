/*
题目：假定 iv 是一个 int 的 vector，下面的程序存在什么错误？你将如何修改？

vector<int>::iterator iter = iv.begin(),
                    mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);

迭代器失效：vector调用insert插入元素之后，iter、mid全部失效！vector 插入会使所有迭代器、引用、指针失效。循环条件iter != mid使用已经失效的迭代器，程序是未定义行为，会崩溃 / 死循环。
插入元素后 vector 大小改变，mid原本指向中间位置，插入元素后中间点已经发生变化。
iter没有更新，插入之后iter变成野迭代器。
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
    std::vector<int> iv{1, 2, 3, 4, 5, 6};
    int some_val = 2;

    vector<int>::iterator iter = iv.begin();

    while (iter != (iv.begin() + iv.size() / 2))
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);
            iter++;
        }
        iter++;
    }

    for (auto &&i : iv)
    {
        cout << i << ' ';
    }
    
    return 0;
}
