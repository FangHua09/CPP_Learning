// **题目描述**：编写一段程序，使用范围 for 语句将字符串内的所有字符用 x 代替。

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
    string s("nihao");
    for (char &i : s)
    {
        i = 'X';
    }
    
    cout << s << endl;
    return 0;
}
