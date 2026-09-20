/*
题目：下列变量的初值分别是什么？

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}

C++ 规则：全局变量（定义在函数外面）执行默认初始化；局部内置类型不初始化，值未定义；string 类无论全局局部都会默认初始化为空字符串。

std::string global_str; 全局对象：初始值空字符串 ""
int global_int; 全局内置 int：默认初始化为 0
int local_int; main 内部局部 int：未初始化，值是垃圾随机数（未定义值）
std::string local_str; 局部 string 对象：类类型，默认初始化为空字符串 ""
*/