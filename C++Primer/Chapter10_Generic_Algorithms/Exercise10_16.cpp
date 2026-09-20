/*
使用 lambda 编写你自己版本的 biggies。

>
> biggies 功能：对单词序列去重排序，统计并打印长度大于等于指定值的所有单词。
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
    auto big_it = find_if(words.begin(), words.end(), [sz](const string &s) -> bool
                          { return s.size() >= sz; });

    // 计算有几个大于
    auto count = words.end() - big_it;
    cout << "长度 >= " << sz << " 的单词有 " << count << " 个：" << endl;

    // 打印
    for_each(big_it, words.end(), [](const string &s)
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
