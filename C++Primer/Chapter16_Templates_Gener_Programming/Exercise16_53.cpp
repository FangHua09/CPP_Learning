/*
 *练习 16.53：编写可变参数 print 函数
 思路：可变参数模板递归打印；非可变参数版本作为递归终止版本。
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
void print(const T &t)
{
    cout << t << endl;
}

template <typename T, typename... Args>
void print(const T &t, const Args &...rest)
{
    cout << t << '\n';
    print(rest...);
}

int main()
{
    print(1);
    cout << '\n';
    print(10, 3.14);
    cout << '\n';
    print(100, 2.718, "hello", string("c++"), 'A');
    cout << '\n';
    return 0;
}

/*
int main()
{
    print(1);                                      // 1个实参 int
    print(10, 3.14);                               // 2个实参 int, double
    print(100, 2.718, "hello", string("c++"), 'A');// 5个不同类型
    return 0;
}
*/