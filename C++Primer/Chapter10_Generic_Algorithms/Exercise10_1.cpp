/*
头文件 algorithm 中定义了一个名为 count 的函数，它类似 find，接受一对迭代器和一个值作为参数。
count 返回给定值在序列中出现的次数。
编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。
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

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 2, 3, 3, 3, 4};
    cout << "3出现的次数： " << count(v.begin(), v.end(), 3) << '\n';
    return 0;
}
