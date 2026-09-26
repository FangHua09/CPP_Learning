/*
练习 13.54：如果定义移动赋值，不改动拷贝交换版赋值运算符，会发生什么？

原拷贝交换版本：HasPtr& operator=(HasPtr rhs)
HasPtr& operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}
当同时存在：移动赋值operator=(HasPtr&&) + 拷贝交换版operator=(HasPtr)
hp = hp2：hp2 左值，调用拷贝交换版本：rhs拷贝构造。
hp = move(hp2)：move(hp2)是右值，优先匹配移动赋值运算符operator=(HasPtr&&)，不会调用拷贝交换版本。
关键：重载决议优先级。右值优先匹配T&&版本。

int main()
{
    HasPtr hp("a"), hp2("b");
    hp = hp2;          // 拷贝交换版本
    hp = move(hp2);    // 调用移动赋值
    return 0;
}
*/
