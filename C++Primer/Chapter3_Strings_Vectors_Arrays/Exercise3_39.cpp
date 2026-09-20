// ①比较两个`string`对象；②比较两个 C 风格字符串。
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::string;

int main()
{
    //1. std::string 比较，直接用 ==
    string s1 = "hello";
    string s2 = "hello";
    string s3 = "world";
    cout << std::boolalpha;
    cout << "string s1==s2: " << (s1 == s2) << "\n";
    cout << "string s1==s3: " << (s1 == s3) << "\n";

    //2. C风格字符串 char*，不能直接 ==（比较地址），要用 strcmp
    const char cstr1[] = "hello";
    const char cstr2[] = "hello";
    const char cstr3[] = "world";
    // strcmp返回0代表内容相等
    cout << "c‑str cstr1==cstr2: " << (strcmp(cstr1, cstr2) == 0) << "\n";
    cout << "c‑str cstr1==cstr3: " << (strcmp(cstr1, cstr3) == 0) << "\n";
    return 0;
}
