/*
题目：重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。

分析：list和vector是不同容器类型，不能直接用==。思路：把list迭代器区间构造一个临时vector<int>，再比较；
或者手写循环逐元素对比。
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
    std::list<int> lst{1,2,3,4};
    std::vector<int> vec1{1,2,3,4};
    std::vector<int> vec2{1,2,3};

    vector<int>Templst (lst.begin(), lst.end());
    if(Templst == vec1) cout << "lst和vec1的元素相等" << '\n';
    return 0;
}
