/*
pos Screen::size() const
{
    return height * width;
}
pos 是 Screen 类内部定义的类型别名：using pos = std::string::size_type;
问题分析
编译报错：pos 不是一个类型名。
原因：当我们在类外部定义成员函数时，返回类型写在 Screen::size() 的前面。此时还没有进入 Screen 的类作用域，编译器并不知道 pos 是什么；pos 是属于 Screen 的内部类型，外面直接写 pos，名字找不到。
只有参数列表后面的 Screen:: 才进入类作用域；返回类型不在类作用域内，必须显式限定。
报错信息：
plaintext
error: ‘pos’ does not name a type
修改方案
返回类型加上类作用域限定符 Screen::
 
Screen::pos Screen::size() const
{
    return height * width;
}
*/