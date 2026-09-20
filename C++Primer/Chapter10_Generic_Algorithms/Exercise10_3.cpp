/*
题目：用accumulate求一个vector<int>中的元素之和。

accumulate定义在头文件<numeric>中，它会把区间内所有元素累加到给定的初始值上。
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
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "元素之和： " << accumulate(vec.begin(), vec.end(), 0) << '\n';
    return 0;
}
