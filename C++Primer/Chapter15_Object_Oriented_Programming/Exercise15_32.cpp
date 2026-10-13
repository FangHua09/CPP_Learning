/*
 *练习 15.32：Query 对象拷贝、移动、赋值、销毁
 Query 内部只有一个成员：shared_ptr<Query_base>，shared_ptr 自带引用计数。
 拷贝（拷贝构造 / 拷贝赋值）
 拷贝 Query 时，会拷贝内部的 shared_ptr，引用计数 +1。
 两个 Query 对象现在共享同一个堆上的 Query_base 派生对象。
 移动（移动构造 / 移动赋值）
 移动 Query，转移 shared_ptr 的管理权，原对象的 shared_ptr 置空，引用计数不变。
 源对象变为空，不再托管那个 Query_base。
 销毁（析构）
 执行Query析构函数：销毁内部shared_ptr，引用计数 -1。
 如果引用计数减到 0，shared_ptr自动调用Query_base虚析构，释放堆上的查询对象。
 一句话：Query 的拷贝控制全部由 shared_ptr 的行为决定。
 */
