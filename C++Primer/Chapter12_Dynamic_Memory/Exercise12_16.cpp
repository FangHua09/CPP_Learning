/*
题目：如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。
原理
unique_ptr不支持拷贝构造、拷贝赋值，它是独占式智能指针，所有权只能移动（std::move），不能共享。拷贝相关成员函数被delete。
*/

#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> p1(new int(100));
    //unique_ptr<int> p2 = p1; // ❌尝试拷贝，编译报错
    return 0;
}
/*
\dev\workspace\C++Learning\C++Primer\Chapter12_Dynamic_Memory\"; if (!(Test-Path output)) { mkdir output }; g++ -g Exercise12_16.cpp -o output/Exercise12_16.exe; ./output/Exercise12_16.exe
Exercise12_16.cpp: In function 'int main()':
Exercise12_16.cpp:14:26: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
   14 |     unique_ptr<int> p2 = p1; // ❌尝试拷贝，编译报错
      |                          ^~
In file included from D:/dev/mingw64/lib/gcc/x86_64-w64-mingw32/16.2.0/include/c++/memory:80,
                 from Exercise12_16.cpp:8:
D:/dev/mingw64/lib/gcc/x86_64-w64-mingw32/16.2.0/include/c++/bits/unique_ptr.h:543:7: note: declared here
  543 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
Exercise12_16.cpp:14:26: note: use '-fdiagnostics-all-candidates' to display considered candidates
   14 |     unique_ptr<int> p2 = p1; // ❌尝试拷贝，编译报错
      |                          ^~
./output/Exercise12_16.exe: 术语 './output/Exercise12_16.exe' 不会被识别为 cmdlet、函数、脚本文件或可执行程序的名称。
请检查名称的拼写或验证路径是否正确(如果包含路径)，然后重试。
*/

//翻译：尝试调用被删除的拷贝构造函数。