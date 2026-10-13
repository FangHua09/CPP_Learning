/*
 *练习 16.6：自己实现 std::begin /std::end（数组版本）
 原理：接收数组引用，推导出数组长度 N。
 begin返回数组首元素指针；end返回尾后指针（arr + N）。
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

template <typename T, size_t N>
T *mbegin(const T (&ref)[N])
{
    return ref;
}

template <typename T, size_t N>
T *mend(const T (&ref)[N])
{
    return ref + N;
}

int main(int argc, char const *argv[])
{
    int a[] = {10, 20, 30};
    auto pbeg = mbegin(a);
    auto pend = mend(a);

    return 0;
}
