/*
编写你自己的单词计数程序。
知识点
map<string, int>，读取单词，map[word]++ 统计单词出现次数。
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
    string word;

    while (cin >> word)
    {
        ++word_count[word];
    }
    for (const auto &p : word_count)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}
