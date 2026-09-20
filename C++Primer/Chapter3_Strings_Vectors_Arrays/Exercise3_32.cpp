// 将上题数组拷贝给另一个数组；再用 vector 重写。
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
    int a[10];
    int b[10];
    for (size_t i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        b[i] = a[i];
    }
    
    for (auto &&i : b)
    {
        cout << i << " "; 
    }

    // vector重写
    vector<int> v1(10);
    
    for (size_t i = 0; i < v1.size(); ++i)
        v1[i] = i;

    vector<int> v2 = v1;

    for (auto &&i : v2)
    {
        cout << i << ' ';
    }
    
    

    return 0;
}
