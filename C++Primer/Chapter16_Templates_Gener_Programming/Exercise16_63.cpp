/*
 *练习 16.63：函数模板统计 vector 中给定值出现次数

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
#include <memory>
using namespace std;

template <typename T>
size_t countOccur(const vector<T> &vec, const T &val)
{
    size_t acount = 0;
    for (auto &&i : vec)
    {
        if (i == val)
            ++acount;
    }
    return acount;
}

int main()
{
    vector<int> vi{1, 2, 2, 3, 2};
    vector<double> vd{1.1, 2.2, 2.2};
    vector<string> vs{"a", "b", "a"};
    cout << countOccur(vi, 2) << endl;
    cout << countOccur(vd, 2.2) << endl;
    cout << countOccur(vs, string("a")) << endl;
    return 0;
}