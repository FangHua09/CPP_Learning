/*
题目：编题目：重写上题的程序，用 list 替代 deque。列出程序要做出哪些改变。

#include <deque> → #include <list>
deque<string> → list<string>
其余代码完全不变。push_back、迭代器遍历对 list 同样支持。list 同样支持双向迭代器。
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
    list<string> dq;
    string line;
    while(cin >> line) dq.push_back(line);

    // 编写一个循环，用迭代器打印 deque 中的元素。
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}


