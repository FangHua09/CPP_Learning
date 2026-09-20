/*
题目描述：为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用 decltype 关键字。你觉得哪种形式最好？为什么？
*/

#include <string>
using namespace std;

//1.类型别名
using arr = string[10];
arr& f1();

//2.尾置返回类型
auto f2() -> string(&)[10];

//3.decltype
string a[10];
decltype(a) &f3();

/*
类型别名（using）可读性最好，优先推荐。把复杂数组类型起别名，简洁直观，不容易写错。
尾置返回类型：可读性次之，适合复杂返回类型。
decltype：需要先定义一个同类型数组用来推导，多了额外定义，可读性差。
核心知识点
using T = xxx类型别名简化复杂数组、指针类型。
尾置返回 auto f() -> 返回类型，把返回类型写在函数参数列表后面。
decltype 根据已有变量推导出类型。

*/