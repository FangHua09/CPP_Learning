/*//example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};

//example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;

错误 1：static double rate = 6.5;
普通静态成员不能在类内初始化；只有static const整型可以类内常量初始化。
double 不是 const 整型，类内写=6.5非法。
错误 2：static vector<double> vec(vecSize);
类内静态成员声明，不能使用圆括号初始化语法 (vecSize)；类内只能等号=或者花括号初始化。圆括号构造只能写在类外定义处。
错误 3：.cpp文件 double Example::rate;
这一句只是声明，没有给 rate 赋初始值；原本期望初始值 6.5 丢失。
错误 4：.cpp文件 vector<double> Example::vec;
这里默认构造空 vector，没有按预期创建vecSize个元素。

✅修正版本
//example.h
#include <vector>
class Example {
public:
    static double rate;
    static const int vecSize = 20;
    static std::vector<double> vec;
};

//example.C
#include "example.h"
double Example::rate = 6.5;
std::vector<double> Example::vec(Example::vecSize);

补充规则：
static const整型 / 枚举类型，可以类内声明同时给常量初始值；其他静态成员类内只做声明，类外源文件定义 + 初始化。
头文件只写类内声明；静态成员的定义必须放在.cpp源文件，不能放在头文件，防止多重包含产生多个定义。

*/