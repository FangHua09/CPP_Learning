/*
题目：编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。
fill_n(iter, n, val) 的功能：从迭代器iter开始，给n个元素赋值val。
如果容器是空的，需要搭配back_inserter来插入元素。
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
    vector<int> vec;
    // 在vec末尾插入10个值为0的int元素
    fill_n(back_inserter(vec), 10, 0);

    for (auto &&i : vec)
    {
        cout << i << ' ';
    }
    
    return 0;
}
