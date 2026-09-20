/*
题目描述：编译第 200 页的 str_subrange 函数，看看你的编译器是如何处理函数中的错误的。
书本错误 str_subrange 源码
//错误版本：返回局部对象的引用
string& str_subrange(const string &str)
{
    if (str.empty()) return "";
    size_t start = 0;
    size_t end = str.size() - 1;
    return str.substr(start, end);
}


解答代码
#include <iostream>
#include <string>
using namespace std;

//错误版本：返回局部对象的引用
string& str_subrange(const string &str)
{
    if (str.empty()) return "";
    size_t start = 0;
    size_t end = str.size() - 1;
    return str.substr(start, end);
}


//修正版本：返回值而不是引用
string str_subrange(const string &str)
{
    if (str.empty()) return "";
    size_t start = 0;
    size_t end = str.size() - 1;
    return str.substr(start, end);
}

int main()
{
    cout << str_subrange("hello") << endl;
    return 0;
}
编译器报错说明
return "";：""是字符串字面量临时对象，不能绑定到非 const 左值引用string&，直接编译报错。
str.substr()返回局部临时 string 对象，函数返回普通引用string&绑定临时对象，产生悬垂引用；部分编译器给出警告，不会直接阻断编译，但运行时为未定义行为。
*/