/*
 *下面哪条声明语句是不正确的？请解释原因。
 cpp
 class Base { ... };
 (a) class Derived : public Derived { ... };
 (b) class Derived : private Base { ... };
 (c) class Derived : public Base;
 ✅ (a) 和 (c) 错误；(b) 合法
 (a) 错误：类不能继承自身。Derived 还没定义完成，不能作为自己的基类。
 (b) 正确：private 是合法的继承方式，私有继承。
 (c) 错误：类的继承声明只能出现在 ** 类定义（带大括号）** 中，不能只写一个分号的类前向声明。类前向声明 class Derived; 不能写继承列表。
 */
