// 统计双字符序列：`ff`、`fl`、`fi`
#include <iostream>
using namespace std;

int main()
{
    char ch, pre;
    int ffCnt = 0, flCnt = 0, fiCnt = 0;

    while (cin.get(pre))
    {
        if (pre == 'f')
        {
            cin.get(ch);
            if (ch == 'f')
                ffCnt++;
            else if (ch == 'l')
                flCnt++;
            else if (ch == 'i')
                fiCnt++;
        }
    }

    cout << "ff:" << ffCnt << " fl:" << flCnt << " fi:" << fiCnt << endl;
    return 0;
}
