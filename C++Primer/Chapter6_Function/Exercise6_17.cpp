/*
题目描述：编写一个函数，判断 string 对象中是否含有大写字母。编写另一个函数，把 string 对象全都改成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？
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

bool has_upper(const string &s)
{
    for (auto &&i : s)
    {
        if (isupper(i))
            return true;
    }
    return false;
}

// // 全部转为小写：需要修改原字符串，普通引用
void to_lower(string &s)
{
    for (auto &&i : s)
    {
        i = tolower(i);
    }
}

int main()
{
    string str1{"HelloWorld"};
    cout << boolalpha << has_upper(str1) << endl;
    to_lower(str1);
    cout << str1 << endl;

    string str2{"abc"};
    cout << has_upper(str2) << endl;
    return 0;
}