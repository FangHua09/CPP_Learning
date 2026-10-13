/*
 *练习 16.4：实现类似 std::find 的模板函数
 模板参数：迭代器类型Iterator，查找值类型T。
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
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

template <typename Iterator, typename T>
Iterator Find(Iterator beg, Iterator end, const T &value)
{
    auto it = beg;
    while (it != end)
    {
        if (*it == value)
            return it;
        ++it;
    }
    return end;
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    auto vit = Find(v.begin(), v.end(), 3);
    if (vit != v.end())
        cout << *vit << endl;

    list<string> lst{"a", "b", "c"};
    auto lit = Find(lst.begin(), lst.end(), "b");
    if (lit != lst.end())
        cout << *lit << endl;
    return 0;
}