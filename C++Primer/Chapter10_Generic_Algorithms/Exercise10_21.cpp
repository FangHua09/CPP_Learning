/*
编写一个 lambda，捕获一个局部 int 变量，并递减变量值，直至它变为 0。一旦变量变为 0，再调用 lambda 应该不再递减变量。
lambda 应该返回一个 bool 值，指出捕获的变量是否为 0。

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
    int n = 5; // 函数局部int变量
    auto decrement = [&n]() -> bool {
        if(n > 0) n--;
        return n == 0;
    };

    // 循环调用，直到返回true（变量归零）
    while (!decrement()) {
        cout << "n 当前值：" << n << endl;
    }
    cout << "n 已到0，结束" << endl;

    // 验证：归零后再调用，不会继续递减
    decrement();
    cout << "再次调用后n的值：" << n << endl;

    return 0;
}
