/*
 *练习 16.2：编写并测试自己版本的 compare 函数模板
 题目：模板 compare，比较两个值，返回true如果第一个小于第二个。
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
bool compare(const T &a, const T &b) { return a < b; }

int main(int argc, char const *argv[])
{
    cout << compare(1, 2) << '\n';
    cout << compare(1.1, 1.2) << '\n';
    cout << compare('a', 'b') << '\n';
    cout << compare(string("a"), string("b")) << '\n';
    return 0;
}
