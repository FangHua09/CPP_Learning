// 输出各种内置类型所占字节大小，使用`sizeof`运算符。
#include <iostream>
using namespace std;

int main()
{
    cout << "bool:          " << sizeof(bool) << endl;
    cout << "char:          " << sizeof(char) << endl;
    cout << "signed char:   " << sizeof(signed char) << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << endl;
    cout << "short:         " << sizeof(short) << endl;
    cout << "unsigned short:" << sizeof(unsigned short) << endl;
    cout << "int:           " << sizeof(int) << endl;
    cout << "unsigned int:  " << sizeof(unsigned int) << endl;
    cout << "long:          " << sizeof(long) << endl;
    cout << "unsigned long: " << sizeof(unsigned long) << endl;
    cout << "long long:     " << sizeof(long long) << endl;
    cout << "float:         " << sizeof(float) << endl;
    cout << "double:        " << sizeof(double) << endl;
    cout << "long double:   " << sizeof(long double) << endl;
    return 0;
}
/*

bool:          1
char:          1
signed char:   1
unsigned char: 1
short:         2
unsigned short:2
int:           4
unsigned int:  4
long:          4
unsigned long: 4
long long:     8
float:         4
double:        8
long double:   16
*/