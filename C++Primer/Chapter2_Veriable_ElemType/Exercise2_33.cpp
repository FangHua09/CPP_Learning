/*
int i = 0;
const int ci = i, &cr = ci;  常量引用本质上属于底层const
auto a = i;      // int
auto b = ci;     // int（顶层const被忽略）
auto c = cr;     // int（引用被忽略，cr是ci别名）
auto d = &i;     // int*
auto e = &ci;    // const int*（底层const保留）
auto &g = ci;    // const int& (带有&的auto会保留顶层const属性,指的是const int ci的顶层const属性保留下来了，和&共同构成了底层const的常量引用)

练习 2.33 判断赋值语句运行结果
a = 42; b = 42; c = 42;
d = 42; e = 42; g = 42;

a = 42; ✅合法；a是普通int，a被赋值为 42。
b = 42; ✅合法；b是int，auto 忽略ci的顶层 const，b赋值 42。
c = 42; ✅合法；c是int，auto 忽略引用，c赋值 42。
d = 42; ❌非法；d是int*指针，不能把整数字面量 42 赋给指针。
e = 42; ❌非法；e是const int*指针，不能把整数 42 赋给指针。
g = 42; ❌非法；g是const int&常量引用，不能通过g修改绑定对象。
*/