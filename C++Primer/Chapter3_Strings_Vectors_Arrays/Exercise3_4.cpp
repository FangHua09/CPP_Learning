/*
**题目描述**：编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。
改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
*/

#include <iostream>
#include <vector>
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
    string s1 = "hello";
    string s2 = "aworld!";

    cout << ((s1 > s2) ? s1 : s2) << '\n'; //输出字典序较大

    cout << ((s1.length() > s2.length()) ? s1 : s2)  << '\n';
    return 0;
}
