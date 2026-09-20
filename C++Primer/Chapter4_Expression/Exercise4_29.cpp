/*
【题目描述】：推断下面代码的输出结果并说明理由。
实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？
int x[10]; int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;

sizeof(x)：x是数组名，sizeof作用数组名得到整个数组总字节，不会退化为指针。sizeof(x)=10*sizeof(int)；*x等价x[0]，类型int。sizeof(x)/sizeof(*x) = 10。
p是指针变量，sizeof(p)得到指针本身字节大小，不是数组大小。
64 位系统：指针 8 字节，sizeof(*p)=4 → 8/4 = 2
32 位系统：指针 4 字节，sizeof(*p)=4 → 4/4 = 1
核心：数组名在sizeof中不会指针退化；数组赋值给指针后丢失数组长度信息。
*/