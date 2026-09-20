// **题目描述**：编写程序，从一个`vector<char>`初始化一个`string`。

/**
 * 思路：
 string提供了迭代器范围构造函数：string(first, last)，会把区间[first, last)的字符拿来构造字符串。
 直接传入vector<char>的首尾迭代器即可。
 * 
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
    vector<char> cv{'H','e','l','l','o'};
    string s1(cv.begin(), cv.end());
    cout << s1 << '\n';

    return 0;
}
