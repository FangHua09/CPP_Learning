/*
 *头文件需要：#include <functional>、#include <algorithm>、using namespace std::placeholders;用到标准库函数对象：greater、not_equal_to、multiplies、modulus；适配器bind
 练习 14.42
 使用标准库函数对象 + 适配器写表达式

 (a) 统计大于 1024 的值有多少个
 greater<int> 二元谓词，bind固定第二个参数 = 1024
 cpp
 auto cnt = count_if(vec.begin(), vec.end(), bind(greater<int>(), _1, 1024));
 含义：_1 > 1024

 (b) 找到第一个不等于pooh的字符串
 not_equal_to<string>
 auto it = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooh"));
 含义：_1 != "pooh"

 (c) 将所有的值乘以 2
 transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2)
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
    vector<int> ivec{1000, 1024, 2000, 3000};
    vector<string> svec{"pooh", "pooh", "abc"};

    // (a)
    auto cnt = count_if(ivec.begin(), ivec.end(), bind(greater<int>(), std::placeholders::_1, 1024)); // 判断_1 > 1024
    cout << "大于1024数量：" << cnt << endl;

    // (b)
    auto it = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), "poth", std::placeholders::_1));
    cout << "第一个不等于pooh：" << *it << endl;

    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), 2, std::placeholders::_1));
    for (auto i : ivec)
        cout << i << " ";

    // bind 里参数顺序，就是传给仿函数的顺序，不要调换！
    return 0;
}
