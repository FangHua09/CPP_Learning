/*
练习 9.47
题目：对字符串"ab2c3d7R4E6"，分别查找所有数字字符、所有字母字符。两个版本：①用find_first_of；②用find_first_not_of

版本 1（find_first_of）
find_first_of(cs, pos)：从 pos 开始，找第一个属于字符集合 cs的字符。
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
    string s = "ab2c3d7R4E6";
    string digits = "0123456789";
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string::size_type pos = 0;
    while ((pos = s.find_first_of(digits, pos)) != string::npos)
    {
        cout << "pos: " << pos << " [pos] :" << s.at(pos) << '\n';
        ++pos;
    }

    pos = 0;

    while ((pos = s.find_first_of(letters, pos)) != string::npos)
    {
        cout << "pos: " << pos << " [pos] :" << s.at(pos) << '\n';
        ++pos;
    }

    /*
    pos: 2 [pos] :2
pos: 4 [pos] :3
pos: 6 [pos] :7
pos: 8 [pos] :4
pos: 10 [pos] :6
pos: 0 [pos] :a
pos: 1 [pos] :b
pos: 3 [pos] :c
pos: 5 [pos] :d
pos: 7 [pos] :R
pos: 9 [pos] :E
    */

    cout << "-------------------------------------" << '\n';

    cout << "数字：";
    pos = 0;
    while ((pos = s.find_first_not_of(letters, pos)) != string::npos)
    {
        cout << s[pos] << " ";
        pos++;
    }
    cout << "\n字母：";
    pos = 0;
    while ((pos = s.find_first_not_of(digits, pos)) != string::npos)
    {
        cout << s[pos] << " ";
        pos++;
    }

    /*
    数字：2 3 7 4 6 
字母：a b c d R E 
    */
    return 0;
}
