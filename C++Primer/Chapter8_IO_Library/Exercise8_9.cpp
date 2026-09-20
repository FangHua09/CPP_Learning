/*
用到头文件：<sstream>, <vector>, <fstream>, <string>, <iostream>
练习 8.9
使用 8.1.2 练习写的函数，打印istringstream对象内容。8.1.2 练习函数：std::istream& print_stream(std::istream &is)，循环读取流，输出内容。
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
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

istream &read_print(istream &is)
{
    string line;
    while(is >> line) cout << line << '\n';

    // 返回流之前对流复位，使其处于有效状态
    is.clear();
    /*
    ⚠️ Windows 小坑：Ctrl+Z 之后会留下换行留在输入缓冲区。如果想要彻底吃掉缓冲区残留字符，可以在 clear 之后加上：
    */
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    return is;
}

int main(int argc, char const *argv[])
{
    string data("hello world cpp primer"); // 直接初始化
    istringstream iss(data); // 让iss绑定字符串， 成为流， 传入函数对应的流参数
    read_print(iss);

    return 0;
}
