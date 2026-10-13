/*
 *debug_rep：模板函数，用来打印类型信息，处理普通对象、指针、const 指针。
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

// 通用版本，处理普通对象
template <typename T>
string debug_rep(const T &t)
{
    return to_string(t);
}

// 重载版本，处理指针
template <typename T>
string debug_rep(T *t)
{
    return "pointer: " + to_string(*t);
}

int main(int argc, char const *argv[])
{
    int a = 10;
    cout << debug_rep(a) << '\n';

    cout << debug_rep(&a) << '\n';
    return 0;
}
