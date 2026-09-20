/*
分析每组第二条声明带来的影响，判断是否合法。

(a)
int calc(int&, int&);
int calc(const int&, const int&);
✅合法重载。形参引用的底层const是区分重载的依据。
传入普通 int 变量，优先匹配calc(int&,int&)；
传入 const int、字面值、表达式，只能匹配calc(const int&,const int&)。
两个构成有效重载，不会冲突。

(b)
int calc(char*, char*);
int calc(const char*, const char*);
✅合法重载。指针底层 const 可以区分重载。
普通char*实参优先匹配第一条；
const char*实参、字符串字面量只能匹配第二条。

(c)
int calc(char*, char*);
int calc(char* const, char* const);
❌不合法，重复声明，编译报错。char* const是顶层 const：修饰指针本身不可修改，不影响指针指向的对象。函数形参的顶层 const 会被忽略，两个函数的形参等价，视为同一个函数，不能重载。
记忆：
底层 const（指向的对象 const）：可以用于重载；
顶层 const（指针 / 引用本身 const）：形参中忽略，不能用来重载。
*/