/*
int null = 0, *p = null;

❌非法
解析：
null是普通int变量，值为整数0；
p是int*指针，指针需要存储内存地址，不能直接把整型数值0直接赋值给指针。

注意：这里的null只是名字叫 null，不是空指针常量，只是一个 int 变量。
int null = 0, *p = &null;
int null = 0, *p = nullptr
*/