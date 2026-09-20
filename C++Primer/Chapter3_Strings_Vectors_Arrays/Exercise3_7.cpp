/*
**题目描述**：就上一题完成的程序而言，如果将循环控制变量的类型设为 char 将发生什么？先估计一下结果，然后实际编程进行验证。
*/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

int main()
{
    string s = "hello";
    for (char c : s)
    {
        c = 'x';
    }
    cout << s << std::endl;
    return 0;
}
