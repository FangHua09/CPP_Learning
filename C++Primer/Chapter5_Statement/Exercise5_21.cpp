#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string prev, curr;
    bool repeated = false;
    while (cin >> curr)
    {
        // 判断：首字符是大写字母，才检查重复
        if (!prev.empty() && isupper(static_cast<unsigned char>(curr[0])) && curr == prev)
        {
            repeated = true;
            cout << "重复单词：" << curr << endl;
            break;
        }
        prev = curr;
    }
    if (!repeated)
    {
        cout << "没有找到以大写开头的连续重复单词" << endl;
    }
    return 0;
}