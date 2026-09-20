/*
**题目描述**：编写一段程序，
创建一个含有 10 个整数的 vector 对象，
然后使用迭代器将所有元素的值都变成原来的两倍。
输出 vector 对象的内容，检验程序是否正确。
*/
#include <iostream>
#include <vector>
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
    vector<int> v;
    int i;
    while(cin >> i) v.push_back(i);

    for (auto &&i : v)
    {
        i = i * 2;
        cout << i << " ";
    }
    
    return 0;
}
