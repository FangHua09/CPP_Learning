/*
题目描述：编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会有用。

struct Foo {  }  // 注意：没有分号
int main()
{
    return 0;
}

解析C++ 中struct / class类型定义结束的}后面必须加分号。struct Foo {}没有分号，编译器认为还在类型声明，把下一行的int main()当成该结构体声明的变量

GCC报错
error: expected ‘;’ before ‘int’
 int main()
 ^~~

*/