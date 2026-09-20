/*
编写一个程序，在一个 vector 而不是一个 set 中保存不重复的单词。使用 set 的优点是什么

set 的优点
set自动保证元素唯一，插入时自动去重，不用手动调用find判断。
set查找是 O (log n)；vector 的find是顺序遍历 O (n)，数据量大时set效率高得多。
set内部自动维护有序。vector 版本需要手动 sort 才能有序。

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<string> words;
    string word;
    while (cin >> word)
    {
        // 如果vector中没有这个单词，才添加
        if (find(words.begin(), words.end(), word) == words.end())
        {
            words.push_back(word);
        }
    }
    return 0;
}
