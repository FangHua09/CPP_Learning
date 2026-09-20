/*
题目描述
编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。
使用迭代器及 insert 和 append 函数将前缀和后缀添加到给定的名字中，将生成的新 string 返回。
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

string add_prefix_suffix_iter(string name, const string &prefix, const string &suffix)
{
    auto it = name.begin();
    auto len = name.length();
    //name.insert(it, {prefix[0], prefix[1], prefix[2]}); // insert如果使用迭代器指定插入点，就不能用字符指针指定新字符的来源
    // 开头插入前缀：迭代器版本的 insert
    name.insert(name.begin(), prefix.begin(), prefix.end()); // 不知道具体长度就用迭代器指代另一个字符串的范围
    name.append(suffix);
    return name;
}

int main()
{
    string name = "Smith";
    string result = add_prefix_suffix_iter(name, "Mr.", " Jr.");
    cout << result << endl; // Mr.Smith Jr.
    return 0;
}