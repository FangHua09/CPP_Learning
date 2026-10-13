/*
 *
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

template <typename T, typename... Args>
void foo(const T &, Args... rest)
{
    cout << sizeof...(Args) << '\n';
    cout << sizeof...(rest) << '\n';
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    foo(i, s, 42, d); // (1)
    foo(s, 42, "hi"); // (2)
    foo(d, s);        // (3)
    foo("hi");        // (4)
    foo(i, s, s, d);  // (5)
    return 0;
}
/*
foo(i, s, 42, d):        sizeof...(Args): 3, sizeof...(rest): 3
foo(s, 42, "hi"):       sizeof...(Args): 2, sizeof...(rest): 2
foo(d, s):               sizeof...(Args): 1, sizeof...(rest): 1
foo("hi"):              sizeof...(Args): 0, sizeof...(rest): 0
foo(i, s, s, d):         sizeof...(Args): 3, sizeof...(rest): 3

考点小结
sizeof... 专门获取参数包元素数量，编译期常量，不计算表达式
template<typename T, typename... Args>：T单独拿第一个参数，剩下全部打包进Args
Args（类型包）和rest（函数参数包）一一对应，元素数量必然相同。
*/
