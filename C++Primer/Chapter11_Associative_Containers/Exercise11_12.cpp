/*
题目描述：编写程序，读入 string 和 int 的序列，将每个 string 和 int 存入一个 pair 中，pair 保存在一个 vector 中。
知识点：std::pair、std::vector、标准输入读取。
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
        vec.push_back({line, n});
    }

    // 输出验证
    for (auto &p : vec)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}
