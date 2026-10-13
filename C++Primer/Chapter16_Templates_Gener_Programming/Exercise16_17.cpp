/*
 *练习 16.17：
 
 typename 和 class 模板类型参数的区别
 作为模板参数声明时：class 和 typename 含义完全一样，没有任何区别
 
 template<class T>   // 等价
 template<typename T>// 等价
 只是关键字不同，都用来声明类型模板参数。
 什么时候必须用 typename当在模板内部，引用一个 ** 依赖模板参数的类型成员（依赖类型名）** 时，必须写 typename，不能用 class。
 语法：typename T::value_type告诉编译器：T::value_type 是一个类型，而不是静态成员变量。示例：
 
 template<typename T>
 void func(const T &c) {
     typename T::size_type s; // 这里 typename 不能省略！
 }

 一句话总结：
 在模板参数列表：class / typename 完全等价；
 在模板体内访问依赖类型成员，只能用 typename。
 */
