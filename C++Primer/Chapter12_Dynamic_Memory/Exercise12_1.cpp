/*
题目：在此代码的结尾，b1 和 b2 各包含多少个元素？
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}

知识点：shared_ptr 共享所有权；类拷贝赋值；局部对象作用域与析构；shared_ptr 引用计数机制。
解答：
代码块结束后，b2 是局部变量，离开作用域被销毁。
b1 和 b2 赋值后共享同一个底层vector，b2.push_back 修改共享容器，容器内共 4 个元素。
b1：4 个元素（"a", "an", "the", "about"）
b2：已经出作用域，对象不复存在。

原理：b2析构仅让 shared_ptr 引用计数减 1，计数不为 0，底层 vector 不会释放，b1继续持有这份数据。
*/
