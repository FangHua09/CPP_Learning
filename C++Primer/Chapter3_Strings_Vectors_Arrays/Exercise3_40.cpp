// 定义两个字符数组，字符串字面量初始化；第三个数组保存拼接结果；`strcpy`、`strcat`完成拼接。
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
    char str1[] = "hello";
    char str2[] = "world";
    char str3[strlen(str1) + strlen(str2) + 1];

    strcpy(str3, str1);
    strcat(str3, str2);

    for (auto &&i : str3)
    {
        cout << i;
    }
    

    return 0;
}
