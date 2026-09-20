/*
题目描述
编写程序处理一个vector<string>，其元素都表示整型值。计算 vector 中所有元素之和。修改程序，使之计算表示浮点值的 string 之和。
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

// sum_int
int sum_int(const vector<string> &v)
{
    int sum = 0;
    for (auto &&s : v)
    {
        sum += stoi(s);
    }
    return sum;
}

// 浮点字符串求和
double sum_double(const vector<string> &vec)
{
    double sum = 0.0;
    for (const auto &s : vec)
        sum += stod(s);
    return sum;
}

int main()
{
    vector<string> int_strs = {"123", "456", "789", "-42"};
    cout << "整型和：" << sum_int(int_strs) << endl;

    vector<string> dbl_strs = {"3.1415", "2.7182", "1.4142", "0.5772"};
    cout << "浮点和：" << sum_double(dbl_strs) << endl;
    return 0;
}