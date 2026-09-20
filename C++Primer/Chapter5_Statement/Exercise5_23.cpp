// 【题目描述】：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
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
    int a, b;
    cin >> a >> b;
    cout << a / b << '\n'; // 10 0 →程序直接崩溃（除零，未处理）
    return 0;
}
