/*题目描述：编写一个函数，令其接受两个参数：一个是 int 型的数，另一个是 int 指针。函数比较 int 的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？
解答代码：*/

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

int larger(int a, const int *b) {
    return (a > *b) ? a : *b;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << larger(a, &b) << endl;

    int c = 30;
    int d = 25;
    cout << larger(c, &d) << endl;
    return 0;
}