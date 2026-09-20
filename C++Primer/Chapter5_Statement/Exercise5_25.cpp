/*
修改上一题，使用 try‑catch 捕获异常。catch 提示用户，询问是否输入新数，重新执行 try 块。
【解答】：外层循环；try 块做输入与除法；catch 捕获异常，提示用户是否继续；用户确认则循环回到 try 重新输入。
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
    int a, b;
    std::cin >> a >> b;
    char ch = 'y';

    while (ch == 'y')
    {
        try
        {
            throw std::runtime_error("divisor is zero");
        }
        catch (const std::exception &err)
        {
            std::cout << err.what() << "\n是否重新输入？输入y继续，其他退出：";
            cin >> ch;
        }
    }

    std::cout << a / b << std::endl;
    return 0;
}