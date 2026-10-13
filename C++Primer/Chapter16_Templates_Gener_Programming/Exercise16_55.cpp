/*
 *练习 16.55：可变参数 print 定义之后，才声明非可变参数版本
 
 template<typename T, typename... Args>
 void print(const T &t, const Args& ...rest)
 {
     cout << t << ", ";
     print(rest...); // 递归调用点
 }
 
 // 终止版本写在可变参数版本后面！！
 template<typename T>
 void print(const T &t)
 {
     cout << t << endl;
 }
     
 会发生什么？
 编译错误！
 编译器自上而下读代码；
 在可变参数模板内部调用print(rest...)做递归；
 当参数包为空，递归到只剩一个参数时，编译器去查找单参数print；
 此时单参数版本还没有被声明，编译器看不见这个终止函数；
 编译器只能看到可变参数版本，会继续尝试匹配可变参数模板：
 print(arg) 尝试匹配 print(T, Args...)，Args 为空包。
 模板要求至少 1 个参数（T），可以附加 0 个或更多 Args，语法上print(x)可以匹配可变参数版本，无限递归展开，编译失败。
 ✅正确写法：把终止版本的声明放在可变参数模板前面，递归的时候编译器能找到终止版本。
 */
