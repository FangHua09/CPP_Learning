/*
说明下列变量的类型和值。
(a) int* ip, i, &r = i;
(b) int i, *ip = 0;
(c) int* ip, ip2;

(a) int* ip, i, &r = i;
ip：int*（int 型指针），没有初始化，值是随机垃圾值（野指针）。
i：int整型，没有初始化，值随机。
r：int&（int 的引用），绑定变量i，是i的别名；r没有独立值，和i共享同一块内存。
⚠️注意：*只修饰紧跟的ip，不是后面所有变量；只有ip是指针，i是普通 int。

(b) int i, *ip = 0;
i：int整型，未初始化，值随机。
ip：int*（int 型指针），初始化为0，等价空指针nullptr，不指向任何对象。

(c) int* ip, ip2;
ip：int*（int 型指针），未初始化，随机垃圾地址（野指针）。
ip2：普通int整型，不是指针！未初始化，值随机。
易错坑：int* ip, ip2;，*仅属于ip，ip2只是 int 变量，不是指针。想要两个指针要写：int *ip, *ip2;。

*/