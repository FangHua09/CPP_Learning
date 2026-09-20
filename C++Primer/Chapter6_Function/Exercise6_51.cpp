//编写 f 四个版本，每个输出区分消息，验证上面匹配结果：
#include <iostream>
using namespace std;

void f(int)
{
    cout << "f(int)" << endl;
}

void f(int, int)
{
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "f(double, double)" << endl;
}

void f(char, char)
{
    cout << "f(char, char)" << endl;
}

int main()
{
    //f(2.56,42);   //二义性，编译报错 多个 重载函数 "f" 实例与参数列表匹配:C/C++(308)
    f(42);         //输出 f(int)
    f(42,0);       //输出 f(int, int)
    f(2.56,3.14);  //输出 f(double, double)
    return 0;
}