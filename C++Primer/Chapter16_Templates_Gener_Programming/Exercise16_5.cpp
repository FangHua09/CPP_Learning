/*
 *练习 16.5：print 模板，接收数组引用，可以处理任意大小、任意类型数组
 利用数组引用模板参数推导：T (&arr)[N]
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

// 使用一个类型模板参数（作为类型），一个非类型模板参数（作为值）
template <typename T, size_t N>
void print(const T (&ref)[N])
{
    for (size_t i = 0; i < N; i++)
    {
        cout << ref[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 3};
    string arr2[] = {"hi", "cpp"};
    print(arr1);
    print(arr2);
    return 0;
}
