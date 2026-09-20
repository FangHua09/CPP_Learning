/*
【题目描述】已知变量：float fval; int ival; char cval; double dval;说明表达式中发生的类型转换，同时说明运算符结合性。
(a) if (fval)(b) dval = fval + ival;(c) dval + ival * cval;
【解答】
(a) if(fval)
转换：float fval → 隐式转换为 bool。0.0 为 false，非 0 为 true。
if条件，无运算符结合性。

(b) dval = fval + ival;
+：ival(int) →提升为float，与fval(float)相加，结果float；+左结合。
=赋值：float结果 →转换为double存入dval；=右结合。

(c) dval + ival * cval;
*优先级高于+：cval(char)整型提升为int，与ival(int)相乘，结果int；*左结合。
乘法得到的int →转换为double，和dval(double)相加，结果double；+左结合。
*/