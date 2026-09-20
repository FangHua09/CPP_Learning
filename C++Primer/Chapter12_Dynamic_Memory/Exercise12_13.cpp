/*
如果执行下面的代码，会发生什么？
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
知识点：shared_ptr 管理的内存禁止手动 delete

解答
❌未定义行为，程序崩溃。
sp拥有这块堆内存；p是sp.get()拿到的裸指针。手动delete p释放内存。等到sp离开作用域，sp析构函数再次尝试释放已经释放过的内存，double free。
*/

