/*
扩展单词计数程序，忽略大小写和标点。例如，"example."、"example," 和 "Example" 应该递增相同的计数器。
知识点
tolower 转小写；ispunct 判断标点，去除单词首尾标点；map 保存标准化后的单词。
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

string clean_word(string s)
{
    string res;
    for (auto &&i : s)
    {
        if (ispunct(i))
            continue;
        res += tolower(i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    map<string, int> word_count;
    string word;
    while (cin >> word)
    {
        word = clean_word(word);
        ++word_count[word];
    }

    for (const auto &p : word_count)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}
