/*
题目描述：解释下面代码执行的结果：
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
知识点：内置指针手动内存管理 vs shared_ptr 引用计数自动内存管理。


解答
内置指针部分：
int *q = new int(42), *r = new int(100);
r = q;
q指向堆上42；r指向堆上100。
r = q：让r也指向42。原来 r 指向的 100 的内存地址丢失，无法 delete，发生内存泄漏。


shared_ptr 部分：
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
q2：指向 42，引用计数 = 1；r2指向 100，引用计数 = 1。
r2 = q2;
赋值：r2放弃原来指向的100，100的引用计数减到 0，自动释放这块内存。
r2指向q2所指的 42，q2的引用计数变为 2。
函数结束时，q2、r2销毁，引用计数递减到 0，自动释放 42。
✅ 无内存泄漏。
对比总结：内置指针赋值，旧内存不会自动释放；shared_ptr 赋值，会自动递减引用计数，计数为 0 则释放内存。
*/

