// 重写统计长度小于等于 6 的单词数量的程序，使用函数代替 lambda。
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

// 谓词函数：判断字符串长度是否<=6
bool leq6(const string& s)
{
    return s.size() <= 6;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "turtle", "programming", "algorithm"};
    cout << count_if(words.begin(), words.end(), leq6) << '\n';
    return 0;
}
