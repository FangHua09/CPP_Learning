/*
int i; double d;
(a) d = i = 3.5;
赋值运算符右结合。
i = 3.5：i是int，浮点数 3.5 截断，i = 3。
d = i：把整数 3 赋值给 double。
结果：i = 3，d = 3.0

(b) i = d = 3.5;
d = 3.5：d是 double，d = 3.5。
i = d：double 值 3.5 赋给 int，小数截断。
结果：i = 3，d = 3.5
*/