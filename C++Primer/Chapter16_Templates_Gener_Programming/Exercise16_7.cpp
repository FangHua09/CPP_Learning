/*
 *练习 16.7：constexpr 模板，返回数组大小
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
constexpr size_t get_array_size(const T (&ref)[N])
{
    return N;
}
int main(int argc, char const *argv[])
{
    int arr[5];
    constexpr size_t sz = get_array_size(arr); // sz=5，编译期求值

    return 0;
}
