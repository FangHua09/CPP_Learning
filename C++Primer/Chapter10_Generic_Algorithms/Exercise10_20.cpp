/*
标准库定义了一个名为 count_if 的算法。类似 find_if，
此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。
count_if 返回一个计数值，表示谓词有多少次为真。
使用 count_if 重写程序中统计有多少单词长度超过 6 的部分。
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
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "turtle", "programming", "algorithm"};
    int count = count_if(words.begin(), words.end(), [](const string &s) -> bool
                         { return s.size() > 6; });
    cout << count << '\n';

    return 0;
}
