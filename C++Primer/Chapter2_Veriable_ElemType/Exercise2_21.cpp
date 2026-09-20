/*
解释下述定义。在这些定义中有非法的吗？如果有，为什么？
int i = 0;
(a) double *dp = &i;
(b) int *ip = i;
(c) int *p = &i;


(a) double *dp = &i; 非法&i是int*类型，不能直接赋值给double*；类型不匹配，int 指针不能存 int 变量地址交给 double 指针。
(b) int *ip = i; 非法i是 int 数值 0；指针变量需要存放地址，不能直接把整型数值赋给指针。（不能把数值当作地址）
(c) int *p = &i; 合法&i获取 int 变量i的地址，存入 int 型指针p。
只有 (c) 合法，(a)(b) 编译报错
*/