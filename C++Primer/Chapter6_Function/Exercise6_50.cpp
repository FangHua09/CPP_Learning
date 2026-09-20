/*
四个重载：
void f(int);
void f(int, int);
void f(double, double = 3.14);
void f(char, char);

(a) f(2.56, 42)
可行函数：
void f(int, int)：2.56 double→int；42 int 匹配
void f(double, double = 3.14)：2.56 精确匹配 double；42 int→double
❌二义性，调用不合法。第一个实参2.56对f(double,double)更好；第二个实参42对f(int,int)更好。没有一个可行函数在所有实参上都不比另一个差，编译器无法选出最佳匹配，二义性报错。

(b) f(42)
可行函数：
void f(int)：42 精确匹配 int；
void f(double, double = 3.14)：42 int→double，第二个形参取默认值。
✅最佳匹配：void f(int)。42 是 int，精确匹配优于 int→double 转换。

(c) f(42, 0)
可行函数：
void f(int, int)：两个实参全部精确匹配 int；
void f(double, double = 3.14)：42→double，0→double。
✅最佳匹配：void f(int, int)，全部实参精确匹配。

(d) f(2.56, 3.14)
可行函数：
void f(int, int)：double→int 两次转换；
void f(double, double = 3.14)：两个实参全部精确匹配 double。
✅最佳匹配：void f(double, double = 3.14)。

*/