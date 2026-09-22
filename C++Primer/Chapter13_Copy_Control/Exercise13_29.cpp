/*
解释swap(HasPtr&, HasPtr&)中对swap的调用不会导致递归循环。
假设我们自定义的HasPtr版本 swap 函数大致长这样：
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap两个string*裸指针
    swap(lhs.i, rhs.i);   // swap两个int
}

函数外层名字是swap（我们自己写的，参数是两个HasPtr&）。
函数内部的swap(lhs.ps, rhs.ps)：传入的实参类型是 **string***，不是HasPtr。
名字查找：using std::swap;引入标准库 swap。内部调用匹配的是标准库std::swap(T,T)模板，实例化为std::swap(string*,string*)，不是我们外层这个接收 HasPtr 引用的 swap 函数。

所以不会递归调用自己，不会产生无限递归循环。
一句话总结：内部 swap 交换的是指针和 int，参数类型不是 HasPtr，调用的是 std::swap，不是 HasPtr 版本 swap。

*/
