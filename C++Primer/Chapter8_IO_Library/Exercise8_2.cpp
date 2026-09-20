/*
题目描述：
试上面函数，调用参数为cin。
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

istream &read_print(istream &is)
{
    int a;
    while (is >> a)
        cout << a << ' '; // 直到读到文件结束标识符

    // 返回流之前对流复位，使其处于有效状态
    //is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
    //is.clear();
    is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
    /*
    ⚠️ Windows 小坑：Ctrl+Z 之后会留下换行留在输入缓冲区。如果想要彻底吃掉缓冲区残留字符，可以在 clear 之后加上：
    */
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    return is;
}

int main(int argc, char const *argv[])
{
    // read_print(std::cin);

    cout << "请输入若干整数，结束按 Ctrl+Z(Windows) / Ctrl+D(Linux)\n";
    read_print(cin);

    cout << "\n--- read_print结束，尝试继续读取一个整数 ---\n";
    int x;
    cin >> x;
    if (cin)
    {
        cout << "成功读到 x = " << x << endl;
    }
    else
    {
        cout << "cin 流依然处于错误状态，读取失败" << endl;
    }

    return 0;
}