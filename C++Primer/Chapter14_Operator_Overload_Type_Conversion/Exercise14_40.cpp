/*
 *题目：重写biggies，用仿函数替换原来 lambda。
 biggies 功能：按长度排序，去除重复，输出长度 >=sz 的单词。
 原版 lambda：[sz](const string &s) { return s.size() >= sz; }
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

class StringLenGreaterEqual
{
private:
    size_t sz;

public:
    StringLenGreaterEqual(size_t sz) : sz(sz) {}
    bool operator()(const string &s)const
    {
        return s.size() >= sz;
    }
};

void biggies(std::vector<std::string> &words, size_t sz)
{
    // 按长度排序，长度相同字典序
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                { return s1.size() <= s2.size(); });
    // 去重
    auto end = unique(words.begin(), words.end());
    words.erase(end, words.end());
    // find_if 使用仿函数替代lambda。找到第一个满足
    auto pos = find_if(words.begin(), words.end(), StringLenGreaterEqual(sz));
    auto count = words.end() - pos;
    cout << "the count of bigger than sz is : " << count << '\n';
    for_each(pos, words.end(), [](const string &s)
             { cout << s << ' '; });
}

int main()
{
    std::vector<std::string> vs{"fox", "quick", "red", "fox", "jumps", "over", "slow", "turtles"};
    biggies(vs, 4);
    return 0;
}