/*
重写单词计数程序，用insert代替下标操作。对比两种写法。

[]：代码简短，语义直观；如果单词不存在自动创建，直接++计数。
insert版本：需要接收insert返回的 pair，再通过迭代器访问 second，代码更长。
缺点：[]会无条件插入元素，即使只想查询；insert只会在键不存在时插入。
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
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, size_t> word_count;
    string line;
    while (cin >> line)
    {
        auto flag = word_count.insert(make_pair(line, 1));
        if (!flag.second)
            ++flag.first->second;
    }

    for (auto &p : word_count)
        cout << p.first << " occurs " << p.second << endl;

    return 0;
}
