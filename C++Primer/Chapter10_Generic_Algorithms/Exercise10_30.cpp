/*
使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

知识点
istream_iterator<int> 绑定cin读取整数，尾后迭代器表示输入结束。
sort 对容器内元素做升序排序。
ostream_iterator<int> 绑定cout，可指定分隔符；copy算法直接将排序后的序列输出到标准输出。
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
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);

    sort(vec.begin(), vec.end());

    ostream_iterator<int> out_iter(cout, " ");
    for (auto &&i : vec)
    {
        out_iter = i;
    }
    
    return 0;
}
