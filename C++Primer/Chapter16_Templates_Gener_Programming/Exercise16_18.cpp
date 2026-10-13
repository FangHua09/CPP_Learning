/*
 *练习 16.18：判断模板声明合法性，修正错误
 (a)
 
 template <typename T, U, typename V> void f1(T, U, V);
 ❌ 非法。模板参数 U 没有说明是类型参数，缺少 typename / class。✅ 修改：
 
 template <typename T, typename U, typename V> void f1(T, U, V);
 (b)
 
 template <typename T> T f2(int &T);
 ❌ 非法。形参名字 T 和模板参数名 T 重名；函数参数不能使用模板参数名作为变量名，发生名字遮蔽。✅ 修改：
 
 template <typename T> T f2(int &x);
 (c)
 
 inline template <typename T> T foo(T, unsigned int*);
 ❌ 非法。inline 是函数修饰符，必须放在 template 之后。✅ 修改：
 
 template <typename T> inline T foo(T, unsigned int*);
 (d)
 
 template <typename T> f4(T, T);
 ❌ 非法。函数缺少返回类型。✅ 修改（假设返回 T）：
 
 template <typename T> T f4(T, T);
 (e)

 typedef char Ctype;
 template <typename Ctype> Ctype f5(Ctype a);
 ✅ 合法typedef char Ctype 的 Ctype 会被模板参数 Ctype 名字遮蔽。函数模板参数 Ctype 覆盖外部 typedef，f5 返回和参数都是模板参数类型，不是 char。
 注意：代码语法没问题，只是容易混淆，不报错。
 */
