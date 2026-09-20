// 同时统计大写、小写元音（`a/A`都计数）
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while (cin >> ch)
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
    }
    cout << "a/A:" << aCnt << "\ne/E:" << eCnt
         << "\ni/I:" << iCnt << "\no/O:" << oCnt << "\nu/U:" << uCnt << endl;
    return 0;
}
