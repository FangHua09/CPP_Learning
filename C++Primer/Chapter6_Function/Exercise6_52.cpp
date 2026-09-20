/*
已知：
void manip(int, int);
double dobj;

转换等级参考：
精确匹配：实参和形参类型完全相同；数组 / 函数转指针；顶层 const 忽略。
const 转换：非 const→const。
类型提升：char/short→int；unsigned short→int；float→double。
算术转换：int↔double、char↔int 等普通算术隐式转换。

(a) manip('a', 'z');
'a'、'z'都是char类型，传给int形参：类型提升（char 提升为 int）。
(b) manip(55.4, dobj);
55.4是 double 字面量，dobj是 double 变量；传给 int 形参：算术转换（double→int）。
*/