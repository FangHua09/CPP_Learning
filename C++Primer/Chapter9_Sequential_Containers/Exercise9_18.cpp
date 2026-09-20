/*
题目：编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素。
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
    deque<string> dq;
    string line;
    while(cin >> line) dq.push_back(line);

    // 编写一个循环，用迭代器打印 deque 中的元素。
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}
