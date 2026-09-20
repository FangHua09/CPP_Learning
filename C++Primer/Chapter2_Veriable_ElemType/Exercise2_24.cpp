/*
在下面这段代码中为什么 p 合法而 lp 非法？
int i = 42;
void *p = &i;
long *lp = &i;


void *p = &i; 合法：void*通用指针，可以存放任意类型对象的地址，可以保存 int 变量的地址。但是不能解引用 void*。
long *lp = &i; 非法：&i类型是int*；lp是long*；指针类型不匹配，不能直接赋值。int 的地址不能直接存给 long 指针。int 和 long 是两种不同类型。
void * 可以接收任意对象地址；其他指针必须严格类型匹配。
*/