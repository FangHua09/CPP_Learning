/*
题目描述：什么情况下while (cin >> i) { }循环会终止？
解答
循环条件cin >> i返回cin对象，做条件判断时检测流的状态。
循环终止两种情况：
遇到文件结束符 EOF：输入流到达末尾。
发生 IO 错误：读取的数据类型与变量i类型不匹配（例如 i 是 int，输入字母），流设置 failbit；或是发生系统级 IO 错误，设置 badbit。
只要流的failbit或者eofbit、badbit被置位，条件为假，循环结束。
注意：goodbit为 true 循环继续；eofbit/failbit/badbit任意一个置位，循环退出。
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

int main(int argc, char const *argv[])
{

    return 0;
}
