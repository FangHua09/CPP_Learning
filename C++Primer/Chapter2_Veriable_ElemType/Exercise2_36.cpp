/*
指出每个变量类型，以及程序结束时候各自的值
int a = 3, b = 4;
decltype(a) c = a; // int
decltype((b)) d = a; // int&

++c; // 4
++d; // 4


decltype(表达式)规则：
表达式是不加括号的变量名 → 得到变量本身类型。
表达式是加括号的变量(var) → 得到引用类型。
a：int，初始 3
b：int，初始 4
decltype(a) c = a;：c → int；用a初始化，c=3
decltype((b)) d = a;：(b)是表达式，推导为 **int&**，d是b的别名，绑定b；d=a → 把a=3赋值给b，此时b=3
执行：
++c;：c自增 → c = 4
++d;：d是b的引用，等价++b → b = 4
*/