/*
哪些初始化合法，说明原因
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;

知识点：1. 普通引用&只能绑定左值（变量），不能绑定字面值常量；const 引用可以绑定常量 / 临时值。2.*const：const 指针（指针本身不可改），定义必须初始化。3.const int *：指向 const 的指针，指针本身可改，不能通过指针修改对象。4. 引用没有const &const这种写法。

(a) int i = -1, &r = 0; 非法普通 int 引用不能绑定字面值常量0，只能绑定变量。
(b) int *const p2 = &i2; 合法（前提 i2 是 int 变量）p2是顶层 const 指针，指针本身不能改；定义必须初始化，保存 i2 地址；可以通过*p2修改 i2 的值。
(c) const int i = -1, &r = 0; 合法i是 const int；const引用允许绑定字面值常量0。
(d) const int *const p3 = &i2; 合法（i2 有效）p3：顶层 const（指针本身不能改）+ 底层 const（指向对象不能通过指针修改）。双重 const，定义必须初始化。
(e) const int *p1 = &i2; 合法底层 const 指针，指向const int；指针 p1 本身可以改变指向，不能用*p1修改 i2。
(f) const int &const r2; 非法引用没有const修饰符；引用本身就不能修改绑定，语法不允许写&const；同时引用必须初始化。
(g) const int i2 = i, &r = i; 合法（i 已经定义）i2用变量 i 初始化；const引用r绑定普通 int 变量 i，允许。
✅合法：b、c、d、e、g； ❌非法：a、f

*/