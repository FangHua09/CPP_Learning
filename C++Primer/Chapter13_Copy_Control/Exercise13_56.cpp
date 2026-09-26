/*
Foo Foo::sorted() const & {
    Foo ret(*this);
    return ret.sorted();
}
结果：无限递归，程序栈溢出崩溃（stack overflow）
分析
sorted() const &：只能被左值 Foo 对象调用。
Foo ret(*this); 创建局部对象ret，ret是左值。
ret.sorted()：ret 是左值，再次调用 sorted() const & 这个版本。
函数无限调用自身，没有终止条件，栈不断增长，最终栈溢出。
✅ 正确写法原本应该：在这个函数内部对 ret 排序，直接 return ret；而不是调用 ret.sorted ()。
*/
