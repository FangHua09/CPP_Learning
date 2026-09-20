/*
题目描述：下面的代码调用了第 413 页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
知识点：shared_ptr 拷贝构造、引用计数机制

解答
✅ 调用是正确的。
shared_ptr<int>(p) 调用拷贝构造函数，新建一个 shared_ptr，和p指向同一块内存，引用计数 +1。
process接收这个 shared_ptr 形参；函数结束时，临时 shared_ptr 销毁，引用计数减 1。
原智能指针p离开作用域时，引用计数降到 0，释放内存。不会发生 double free。
区分：12.10 是shared_ptr<int>(p)（传入 shared_ptr 对象）；
12.11 才是shared_ptr<int>(p.get())（传入裸指针），我刚才把两题混在一起了。
*/

