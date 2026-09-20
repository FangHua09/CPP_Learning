/*
示例 1：while 典型场景（读取 cin 输入）
while 版本：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        cout << s << endl;
    }
    return 0;
}
改写为 for 循环：
string s;
for( ; cin >> s; )
{
    cout << s << endl;
}


示例 2：for 典型场景（下标遍历）
for 版本：
int arr[] = {1,2,3,4,5};
for(int i = 0; i < 5; ++i)
{
    cout << arr[i] << endl;
}
改写 while：
int i = 0;
while(i <5)
{
    cout << arr[i] << endl;
    ++i;
}
倾向选择：
循环变量初始化、条件、更新都很清晰，优先for，把循环控制集中写在头部；
循环条件不是简单索引递增，更新位置分散在循环内部，优先while，代码更清晰。
*/