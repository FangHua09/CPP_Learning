//题目：假定name和numbers定义如 325 页所示，numbers.find(name)返回什么？

/*
题目：假定name和numbers定义如 325 页所示，numbers.find(name)返回什么？
书中定义：
cpp
运行
string numbers("0123456789"), name("r2d2");
string::find(sub)：查找子串sub在字符串中的位置。
numbers是纯数字字符串，里面不存在子串"r2d2"（包含字母 r、d）。

所以返回 string::npos（代表查找失败）✅
*/