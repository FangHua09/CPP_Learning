/*
题目描述：在上一题的程序中，至少有三种创建 pair 的方法。编写此程序的三个版本，分别采用不同的方法创建 pair。解释你认为哪种形式最易于编写和理解，为什么？
知识点：三种构造 pair 方式：make_pair、pair<string,int>(s,n)、{s,n}列表初始化 (C++11)。
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
#include <functional>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    int n;
    vector<pair<string, int>> vec;

    while(cin >> line >> n) {
        // 使用初始化列表
        // vec.push_back({line, n});

        // 使用make_pair
        //vec.push_back(make_pair(line, n));

        // 使用显式构造pair
        vec.push_back(pair<string, int>(line, n));
    }

    // 输出验证
    for (auto &p : vec)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}
