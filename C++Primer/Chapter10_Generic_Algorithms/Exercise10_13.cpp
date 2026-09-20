/*
题目描述
编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有 5 个或更多字符。使用此函数划分 words。打印出长度大于等于 5 的元素。


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

// 判断字符串长度是否>=5的谓词
bool longerThan5(const string& s)
{
    return s.size() >= 5;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "turtle"};

    auto end_partiton = partition(words.begin(), words.end(), longerThan5);

    auto it = words.begin();

    while(it != end_partiton) {
        cout << *it << ' ';
        ++it;
    }
    return 0;
}
