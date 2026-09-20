// **题目描述**：分别用 while 循环和传统的 for 循环重写第一题的程序，你觉得哪种形式更好呢？为什么？

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
    string s("hello");
    decltype(s.size()) index = 0;
    
    while(index != s.size()) {
        s[index] = 'X';
        index++;
    }

    cout << s << endl;

    string s2("world");
    for (decltype(s.size()) i = 0; i < s.size(); i++)
    {
        s2[i] = 'X';
    }
    cout << s2 << endl;
    


    return 0;
}
