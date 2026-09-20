/*
使用逗号运算符重写 1.4.1 节 while 循环，去掉块，对比可读性
原 1.4.1 节代码（带块）
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
    {
        sum += val;
        ++val;
    }
    std::cout << sum << std::endl;
    return 0;
}
使用逗号运算符改写（去掉花括号块）
逗号运算符：,，会依次执行左右表达式，返回右侧表达式的值。
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    // 逗号运算符，把两条语句合并成一条表达式语句，不需要{}块
    while (val <= 10)
        sum += val, ++val;
    std::cout << sum << std::endl;
    return 0;
}
可读性分析
功能完全等价，运行结果一样。
可读性降低。
逗号把多个操作挤压到一行，阅读者不容易一眼看出循环内部执行了两件事（累加、自增）；原本花括号块可以很直观区分循环体范围。
工程实践不推荐这种写法，可读性优先。
*/