/*
说明定义含义，找出不合法
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;

解答如下： 
(a) int i, *const cp; 非法cp是int* const指针（指针本身 const），const 指针定义必须初始化，这里没有初始化。i 是普通 int 未初始化。
(b) int *p1, *const p2; 非法p2是int* const const 指针，必须初始化，未初始化。p1普通 int 指针。
(c) const int ic, &r = ic; 非法ic是const int常量，const 变量必须初始化，ic 没有初始值。
(d) const int *const p3; 非法双重 const 指针，指针本身不能改，定义必须初始化，没有初始化。
(e) const int *p; 合法底层 const 指针，指向 const int；指针 p 本身可以改变指向，只限制不能通过*p修改对象；指针可以不初始化（野指针）。
小结：所有*const（顶层 const 指针）、普通 const 变量，定义时必须初始化。const int *不需要初始化。

*/