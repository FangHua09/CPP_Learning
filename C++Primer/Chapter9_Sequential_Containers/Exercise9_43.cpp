/*
编写一个函数，接受三个 string 参数 s、oldVal 和 newVal。
使用迭代器及 insert 和 erase 函数将 s 中所有 oldVal 替换为 newVal。
测试你的程序，用它替换通用的简写形式，如将 "tho" 替换为 "though"，将 "thru" 替换为 "through"。
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

void replace_all_iter(string &s, const string &oldVal, const string &newVal)
{
    string::size_type pos = 0;
    // 不断找oldval第一次出现的索引
    // 用于保存oldVal的字长
    string::size_type oldValLen = oldVal.length();
    while ((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.erase(pos, oldValLen); // 删除从pos下标开始，oldVal的长度
        s.insert(pos, newVal);   // 在pos位置之前插入newVal
        // 处理完记得pos自增
        ++pos;
    }
}

int main(int argc, char const *argv[])
{

    string str = "tho is short, thru is also short";
    replace_all_iter(str, "tho", "though");
    replace_all_iter(str, "thru", "through");
    cout << str << endl;
    // tho is short, thru is also short
    //though is short, through is also short

    return 0;
}
