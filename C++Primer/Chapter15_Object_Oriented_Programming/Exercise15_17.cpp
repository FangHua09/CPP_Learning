/*
 *练习 15.17：尝试定义 Disc_quote 对象，观察编译器报错
 cpp
 Disc_quote dq; // 错误！
 报错原因
 Disc_quote包含纯虚函数 net_price，属于抽象类。C++ 规定抽象类不能实例化（不能创建该类对象）。
 典型编译器报错信息（g++）
 plaintext
 error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
 note: because the following virtual functions are pure within ‘Disc_quote’:
 note: virtual double Disc_quote::net_price(size_t) const
 只有派生类（Bulk_quote、Limit_quote）实现了全部纯虚函数，才可以实例化。
 */
