/*
Exercise1_2
编写一个模板函数 count，返回值是数组 a[0:n-1] 的数值个数。测试你的代码。
题意：统计数组 a[0]~a[n-1] 中等于给定目标值的元素数量。
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

template <typename T>
int count(const T a[], int n, const T &value)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            ++res;
    }
    return res;
}

// 测试
int main()
{
    int arr[] = {1, 2, 2, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << count(arr, n, 2) << endl; // 输出3

    double darr[] = {1.1, 2.2, 2.2, 3.3};
    int dn = sizeof(darr) / sizeof(darr[0]);
    cout << count(darr, dn, 2.2) << endl; // 输出2
    return 0;
}