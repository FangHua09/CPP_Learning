/*
使用一个 map 迭代器编写一个表达式，将一个值赋予一个元素。
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
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> m = {{"first", "second"}}; // 记住里面的pair要加一层大括号
    map<string, string>::iterator it = m.begin();

    // 修改第一个元素的值
    it->second = "2nd";
    cout << it->first << " " << it->second << '\n';
    return 0;
}
