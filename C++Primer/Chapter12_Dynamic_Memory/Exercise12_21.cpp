/*
原版：
string& deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

题目版本：
string& deref() const {
    return (*check(curr, "dereference past end"))[curr];
}
    
✅ 原版更好理由：
原版将check返回的shared_ptr保存到局部变量p。check返回的shared_ptr在p的生命周期内保持存活，保证 vector 不会被销毁。
题目写法：check返回的临时shared_ptr在整条表达式结束就销毁。虽然在此场景下依然可以正常运行，但写法风险更高。
可读性差：把函数调用、解引用、下标写在一行，不容易看懂。
若表达式更复杂，临时对象提前销毁可能引发未定义行为。
一句话：分开保存 shared_ptr 更安全，可读性更好。
*/

