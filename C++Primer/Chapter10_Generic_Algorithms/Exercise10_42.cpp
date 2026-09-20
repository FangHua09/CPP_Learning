/*
使用 list 代替 vector 重新实现 10.2.3 节（第 343 页）中的去除重复单词的程序。
原程序逻辑：读取单词存入容器，排序，消除重复单词，输出不重复单词。
⚠️关键点：list不支持标准库 sort，要使用 list 自带成员函数 sort()；list 自带unique()成员函数，不要用 std::unique。
知识点
std::list 是双向链表，不支持随机访问迭代器，不能使用 <algorithm> 的 sort，提供成员函数 list::sort()。
list 自带成员函数 list::unique()，直接删除连续重复元素，比通用std::unique更适合链表。
原 vector 版本：sort + erase(unique, end)；list 版本：list.sort() + list.unique()。
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
    list<string> lst;
    string line;
    while (cin >> line)
        lst.push_back(line);

    // 自带排序
    lst.sort();

    // 自带去重
    lst.unique();

    // 输出结果
    for (const auto &w : lst)
    {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
