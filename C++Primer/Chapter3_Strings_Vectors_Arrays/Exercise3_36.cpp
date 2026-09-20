/*
练习 3.36
①比较两个数组是否相等；②比较两个 vector 对象是否相等。
数组版本
数组不能直接用==比较，数组名会退化为指针，==只会比较首地址，不是比较内容。需要：先比较长度，再逐个元素用指针循环对比。
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

bool checkEqual(const int *a1, size_t s1, const int *a2, size_t s2) {
    if (s1 != s2)
        return false;
    for (size_t i = 0; i < s1; ++i)
    {
        if (a1[i] != a2[i])
            return false;
    }
    return true;  
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    int arr3[] = {1,2,3};

    cout << checkEqual(arr1, 5, arr2, 5) << '\n';

    vector<int> v1{1,2,3,4,5};
    vector<int> v2{1,2,3,4,5};
    vector<int> v3{1,2,3};

    cout << (v1 == v2) << '\n';

    return 0;
}
