/*
编写函数，接受一个 forward_list<string> 和两个 string 共三个参数。
函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置。
若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。
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

void insert_after_str(forward_list<string> &flst, const string &str1, const string &str2)
{
    auto pre = flst.before_begin();
    auto cur = flst.begin();
    bool flag = false;
    while (cur != flst.end())
    {
        if (*cur == str1)
        {
            flag = true;
            pre = flst.insert_after(pre, str2);
        }
        pre = cur;
        ++cur;
    }
    if (!flag)
    {
        flst.insert_after(pre, str2);
    }
}

int main()
{
    forward_list<string> flst{"aa", "bb", "cc", "dd"};

    // 测试1：找到目标字符串
    insert_after_str(flst, "bb", "XX");
    cout << "找到bb后插入XX: ";
    for (auto &s : flst)
        cout << s << " ";
    cout << endl;

    // 测试2：未找到目标字符串
    insert_after_str(flst, "zz", "YY");
    cout << "没找到zz插入YY到末尾: ";
    for (auto &s : flst)
        cout << s << " ";
    cout << endl;

    return 0;
}