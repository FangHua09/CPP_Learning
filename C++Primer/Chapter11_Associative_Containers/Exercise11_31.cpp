/*
题目描述：编写程序，定义一个作者及其作品的 multimap。使用find在 multimap 中查找一个元素并用erase删除它。确保你的程序在元素不在 map 中时也能正常运行。
知识点：multimap::find；迭代器有效性判断；erase(迭代器)只删除找到的单个元素（不是全部同 key 元素）。
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    multimap<string, string> books;
    books.insert({"Harry Porter", "J.K. RoLing"});
    books.insert({"Lu Xun", "Diary of a Madman"});
    books.insert({"Lu Xun", "The True Story of Ah Q"});
    books.insert({"Mo Yan", "Red Sorghum"});

    // 查找一个元素并删除
     multimap<string, string>::iterator it = books.find("Lu Xun");
    if (it != books.end())
    {
        books.erase(it); // 删除找到的这一条，不是全部Lu Xun
    }

    for (auto &&entry : books)
    {
        cout << entry.first << '\n' << entry.second << '\n';
    }
    
    return 0;
}
