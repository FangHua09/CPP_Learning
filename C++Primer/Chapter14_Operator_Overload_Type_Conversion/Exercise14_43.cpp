/*
 *使用标准库函数对象判断：给定 int 值val，能否被容器所有元素整除。数学条件：val % elem == 0。只要有一个元素取模不为 0，就不满足。modulus<int>：二元函数对象，modulus()(a,b) 返回 a % b。
 思路：count_if统计有多少个元素，使得 val % elem !=0。统计结果 = 0，说明全部可以整除。
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

int main(int argc, char const *argv[])
{
    vector<int> v{2, 4, 8};
    auto f = bind(modulus<int>(), 16, std::placeholders::_1);
    auto cnt = count_if(v.cbegin(), v.cend(), f) == 0; // 每个都会返回取余结果，返回n说明有n个数不能被整除
    cout << cnt << '\n';
    return 0;
}
