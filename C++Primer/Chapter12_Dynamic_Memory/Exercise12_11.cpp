/*
题目描述：如果我们像下面这样调用process，会发生什么？
process(shared_ptr<int>(p.get()));
知识点：裸指针构造 shared_ptr，两套独立引用计数
解答
❌ 未定义行为，程序会崩溃。
p.get()取出裸指针，用裸指针构造全新独立的 shared_ptr 临时对象。
临时 shared_ptr 和原p各自维护独立引用计数，都认为自己独占这块内存。
process执行完，临时 shared_ptr 析构，释放内存；后续p析构时，再次释放同一块内存，double free。
*/

