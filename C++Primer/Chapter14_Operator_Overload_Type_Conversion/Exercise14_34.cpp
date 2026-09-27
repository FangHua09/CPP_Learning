/*
 *if-then-else 仿函数
 调用运算符接收三个形参：判断第一个，条件成立返回第二个；否则返回第三个。
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

class IfThenElse
{
public:
    string operator()(bool flag, const string &s1, const string &s2)
    {
        return (flag) ? s1 : s2;
    }
};

int main(int argc, char const *argv[])
{
    IfThenElse ite;
    cout << ite(true, "hello", "world");
    return 0;
}
