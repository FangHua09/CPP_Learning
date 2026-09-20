// if 统计 cin 输入文本中元音字母数量

#include <iostream>
using namespace std;

int main()
{
    char ch;
    int vowelCnt = 0;
    while (cin >> ch)
    {
        if (ch == 'a')
            ++vowelCnt;
        else if (ch == 'e')
            ++vowelCnt;
        else if (ch == 'i')
            ++vowelCnt;
        else if (ch == 'o')
            ++vowelCnt;
        else if (ch == 'u')
            ++vowelCnt;
    }
    cout << "元音字母总数：" << vowelCnt << endl;
    return 0;
}
