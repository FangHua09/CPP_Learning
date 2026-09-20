// 重写 biggies，用 `partition` 代替 `find_if`。
// 注：`partition` 不保证组内元素顺序，输出顺序可能不同，但数量一定正确。
/*
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

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 排序
    auto end_it = unique(words.begin(), words.end());
    words.erase(end_it, words.end()); // 按照字典序排序并且去重
}

void biggies(vector<string> &words, string::size_type sz)
{
    elimDups(words); // 按字典序排序并且去重
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) -> bool
                { return s1.size() < s2.size(); }); // 按长度从小到大排序并且保持内部相对顺序

    // 获取一个迭代器 找到words里第一个大于等于sz的串的迭代器
    auto end_it = partition(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz;}); // 注意partition划分不保证顺序 但数量一定正确，同时左区间符合要求，又区间不符合， 返回最后一个满足元素的下一个位置。

    // 计算有几个大于
    auto count = end_it - words.begin();
    cout << "长度 >= " << sz << " 的单词有 " << count << " 个：" << endl;

    // 打印
    for_each(words.begin(), end_it, [](const string &s)
             { cout << s << ' '; });
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "turtle"};
    biggies(words, 5);
    return 0;

    /*
    长度 >= 5 的单词有 3 个：
jumps quick turtle
    */
}
