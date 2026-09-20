/*
**题目描述**：如何从一个`list<int>`初始化一个`vector<double>`？
从一个`vector<int>`又该如何创建？编写代码验证你的答案。

思路：使用迭代器区间初始化。list<int>与vector<double>容器类型不同，
不能直接拷贝构造；但int可以转换为double，传入首尾迭代器即可。

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
    // 如何从一个`list<int>`初始化一个`vector<double>`？编写代码验证你的答案。
    list<int> l{1, 2, 3};
    vector<double>v1 (l.begin(), l.end());
    for (auto &&i : v1)
    {
        cout << i << ' ';
    }

    //从一个`vector<int>`又该如何创建？
    vector<int>v2{1, 2, 3};
    vector<double>v3 (v2.begin(), v2.end());
    for (auto &&i : v3)
    {
        cout << i << ' ';
    }
    



    
    return 0;
}
