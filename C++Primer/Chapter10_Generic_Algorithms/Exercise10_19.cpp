// 用 `stable_partition` 重写前一题的程序，在划分后的序列中维持原有元素的顺序。
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
    // `stable_partition` 是稳定划分算法，谓词判定为 “相等” 的元素会保留排序前的相对顺序。
    auto end_part = stable_partition(words.begin(), words.end(), [sz](const string &s) -> bool
                                     { return sz <= s.size(); });

    // 计算有几个大于
    auto count = end_part - words.begin();
    cout << "长度 >= " << sz << " 的单词有 " << count << " 个：" << endl;

    // 打印
    for_each(words.begin(), end_part, [](const string &s)
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
