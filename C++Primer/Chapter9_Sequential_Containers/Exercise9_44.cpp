/*
# 练习9.44
**题目描述**
重写上一题的函数，这次使用一个下标和 `replace`。
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

void replace_all_index(string &s, const string &oldVal, const string &newVal)
{
    string::size_type pos = 0;
    // 用于保存oldVal的字长
    string::size_type oldValLen = oldVal.length();
    while ((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.replace(pos, oldValLen, newVal);
        // 处理完记得pos自增
        ++pos;
    }
}

int main()
{
    string str = "tho is short, thru is also short";
    replace_all_index(str, "tho", "though");
    replace_all_index(str, "thru", "through");
    cout << str << endl;
    // though is short, through is also short
    return 0;
}