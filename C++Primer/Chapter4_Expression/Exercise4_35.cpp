/*
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
判断表达式是否存在隐式类型转换，有则写出转换。(a) cval = 'a' + 3;(b) fval = ui - ival * 1.0;(c) dval = ui * fval;(d) cval = ival + fval + dval;
【解答】(a) cval = 'a' + 3;✅存在隐式转换
'a'(char)整型提升 →int，与3(int)相加，结果int。
赋值：int →char（可能截断）。

(b) fval = ui - ival * 1.0;✅存在隐式转换
ival(int) →double，与1.0(double)相乘得double。
ui(unsigned int) →double，执行减法，结果double。
赋值：double →float（精度损失风险）。

(c) dval = ui * fval;✅存在隐式转换
ui(unsigned int) →float，与fval(float)相乘得到float。
赋值：float →double。

(d) cval = ival + fval + dval;✅存在隐式转换
ival(int) →float，和fval(float)相加得float。
float →double，和dval(double)相加得double。
赋值：double →char（截断）。
*/