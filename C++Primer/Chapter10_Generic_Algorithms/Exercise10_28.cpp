/*
一个 vector 中保存 1 到 9，将其拷贝到三个其他容器中。
分别使用 inserter、back_inserter 和 front_inserter 将元素添加到三个容器中。
对每种 inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。

知识点
back_inserter：尾插，顺序不变 1,2,3,4,5,6,7,8,9。
front_inserter：头插，每次插最前面，序列反转 9,8,7,6,5,4,3,2,1。
inserter：在容器 begin () 前插入，等价头插，序列反转 9,8,7,6,5,4,3,2,1。
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
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> dq_back, dq_front, dq_inserter;

    copy(src.begin(), src.end(), front_inserter(dq_front));
    copy(src.begin(), src.end(), inserter(dq_inserter, dq_inserter.begin()));
    copy(src.begin(), src.end(), back_inserter(dq_back));

    cout << "back_inserter: ";
    for (auto v : dq_back)
        cout << v << " ";
    cout << "\nfront_inserter: ";
    for (auto v : dq_front)
        cout << v << " ";
    cout << "\ninserter: ";
    for (auto v : dq_inserter)
        cout << v << " ";
    cout << endl;
    return 0;
}
