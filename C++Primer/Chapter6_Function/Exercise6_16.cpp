/*
题目描述：下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
bool is_empty(string& s) { return s.empty(); }
*/

#include <iostream>
#include <string>
using namespace std;

// 原函数，存在局限
// bool is_empty(string& s) { return s.empty(); }

// 改进版本：使用const常量引用
bool is_empty(const string& s)
{
    return s.empty();
}

int main()
{
    cout << boolalpha;
    string s1;
    string s2{"hello"};
    cout << is_empty(s1) << endl;
    cout << is_empty(s2) << endl;
    cout << is_empty("") << endl;
    return 0;
}