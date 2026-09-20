/*
题目：解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。

(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;


(a)
错误：不能在cin输入语句内部定义变量，变量必须先定义，再使用。
修改：
cpp
运行
int input_value;
std::cin >> input_value;

(b)
错误：列表初始化（花括号{}），double值3.14赋给int，会发生窄化转换，编译器报错 / 警告；浮点数转整数丢失小数部分，花括号初始化不允许窄化。
修改：
cpp
运行
int i = 3;
//或者 double i = {3.14};

(c)
错误：wage变量没有声明定义，直接使用；连续赋值，wage未定义。
修改：
cpp
运行
double salary, wage;
salary = wage = 9999.99;

(d)
可以编译（非列表初始化）：把3.14的小数部分截断，i得到整数3；会丢失精度，编译器给出警告，但语法合法。
区别：int i{3.14};花括号初始化是非法窄化；int i=3.14;普通赋值语法允许，仅警告。
如果想要消除警告：int i = 3;
*/