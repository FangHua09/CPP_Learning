// 改写 6.10，用引用而非指针交换两个整数；对比哪种更容易使用，原因。
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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 666;
    int b = 999;
    swap(a, b);
    cout << a << " " << b << '\n';
    return 0;
}
