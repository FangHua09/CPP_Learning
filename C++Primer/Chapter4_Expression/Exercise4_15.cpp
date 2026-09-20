/*
double dval; int ival; int *pi;
dval = ival = pi = 0;



赋值右结合，等价：dval = (ival = (pi = 0));
pi = 0合法，指针置空；
ival = pi：非法，不能把指针直接赋值给 int 变量；指针和 int 类型不匹配，编译报错。


修改方案：分开赋值
pi = nullptr;
ival = 0;
dval = 0;
*/