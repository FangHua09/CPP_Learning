/*
为什么read用普通引用；print用const引用？
read(Sales_data&)普通引用：read 函数需要修改传入的Sales_data对象，把输入读到对象成员中；const引用不能修改，所以不能加const。
print(const Sales_data&)const 引用：print 只读取对象数据做输出，不会修改对象。使用const引用：
可以避免拷贝大对象，提升效率；
可以接收const Sales_data对象作为实参；
编译器检查，防止意外修改数据。
*/