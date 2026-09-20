// 题目描述：编写 4 个函数，分别对两个 int 值执行加、减、乘、除运算；在上一题创建的 vector 对象中保存指向这些函数的指针。
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

// 四则运算函数
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return b == 0 ? 0 : a / b; }

int main(int argc, char const *argv[])
{
    // 声明一个vector
    using PF = int (*)(int, int);
    vector<PF> v;
    // v.push_back(add);
    // v.push_back(sub);
    // v.push_back(mul);
    // v.push_back(divi);

    v = {add, sub, mul, divi};

    return 0;
}
