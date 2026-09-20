/*
增加统计空格、制表符、换行符
cin >> ch会跳过空白字符，要用cin.get(ch)读取每一个字符包括空白。
*/
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;

    while (cin.get(ch))
    {
        if (ch == 'a' || ch == 'A')
            ++aCnt;
        else if (ch == 'e' || ch == 'E')
            ++eCnt;
        else if (ch == 'i' || ch == 'I')
            ++iCnt;
        else if (ch == 'o' || ch == 'O')
            ++oCnt;
        else if (ch == 'u' || ch == 'U')
            ++uCnt;
        else if (ch == ' ')
            ++spaceCnt;
        else if (ch == '\t')
            ++tabCnt;
        else if (ch == '\n')
            ++newlineCnt;
    }
    cout << "a/A:" << aCnt << "\ne/E:" << eCnt << "\ni/I:" << iCnt
         << "\no/O:" << oCnt << "\nu/U:" << uCnt << endl;
    cout << "空格:" << spaceCnt << " 制表符:" << tabCnt << " 换行:" << newlineCnt << endl;
    return 0;
}
