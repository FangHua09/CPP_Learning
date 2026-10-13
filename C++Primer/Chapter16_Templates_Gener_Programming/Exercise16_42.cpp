/*
 *template <typename T> void g(T&& val);T&& 是万能引用：
 实参是左值：T 推导为左值引用类型；引用折叠：X& && → X&
 实参是右值：T 推导为普通类型；引用折叠：X && && → X&&
 变量：int i = 0; const int ci = i;
 
 练习 16.42
 (a) g(i);i 是 int 左值
 T = int&
 val 类型：int& && 折叠 → int&
 (b) g(ci);ci 是const int左值
 T = const int&
 val 类型：const int& && 折叠 → const int&
 (c) g(i * ci);i*ci是算术表达式，结果为int 右值
 T = int
 val 类型：int&&
 
 */
