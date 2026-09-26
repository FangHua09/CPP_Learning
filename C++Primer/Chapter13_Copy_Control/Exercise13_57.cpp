/*
Foo Foo::sorted() const & {
    return Foo(*this).sorted();
}
不会无限递归，正常运行
分析
Foo(*this)：创建一个临时 Foo 对象，临时对象是右值。
Foo(*this).sorted()：调用sorted()时，调用者是右值临时对象，匹配重载 Foo sorted() &&（右值版本的 sorted）。
调用的是右值版本 sorted，不再调用本const &版本，不会递归。
两个重载配套：
cpp
Foo sorted() const &; //左值对象调用
Foo sorted() &&;      //右值对象调用，可以就地排序并返回
*/
