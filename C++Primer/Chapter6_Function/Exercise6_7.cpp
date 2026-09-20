// 编写一个函数，当它第一次被调用时返回 0，以后每次被调用返回值加 1。
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

int f()
{
    static int a = 0;
    return a++;
}

int main(int argc, char const *argv[])
{
    cout << f() << '\n';
    cout << f() << '\n';
    cout << f() << '\n';
    cout << f() << '\n';
    return 0;
}
