/*
题目描述
编写 fact.cc 和 factMain.cc，两个文件都包含 Chapter6.h，体会分离式编译。
fact.cc：存放函数实现定义
factMain.cc：存放 main 主函数，调用头文件声明的函数
Chapter6.h：存放函数声明（上一题完成）

Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> g++ -c fact.cc
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> g++ -c factMain.cc
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> g++ fact.o factMain.o -o factApp
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> ./factApp
fact(5) = 120
abs(-12) = 12

*/