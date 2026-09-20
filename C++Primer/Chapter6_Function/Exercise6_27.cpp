//题目描述：编写一个函数，它的参数是 initializer_list<int> 类型的对象，函数的功能是计算列表中所有元素的和。
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

int sum(initializer_list<int> il) {
    int ans = 0;
    for (auto &&i : il)
    {
        ans += i;
    }
    return ans;
}

int main()
{
    cout << sum({1,2,3,4}) << endl;
    cout << sum({10,20,30}) << endl;
    cout << sum({}) << endl;
    return 0;
}