// **题目描述**：编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分
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
    string s;
    getline(cin, s);

    // 原始字符串包含标点符号
    for (auto &i : s)
    {
        if(!ispunct(i)) cout << i;
    }
    
    return 0;
}
