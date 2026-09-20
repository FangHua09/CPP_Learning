// 题目描述：给 make_plural 函数的第二个形参赋予默认实参's'，利用新版本的函数输出单词 success 和 failure 的单数和复数形式。
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

string make_plural(size_t crt, const string &word, const string &ending = "s"){
    return (crt > 1) ? word + ending : word;
}

int main()
{
    cout << make_plural(1, "success") << endl;    //单数
    cout << make_plural(2, "success", "es") << endl;//复数successes

    cout << make_plural(1, "failure") << endl;    //单数
    cout << make_plural(2, "failure") << endl;    //复数，使用默认's'
    return 0;
}