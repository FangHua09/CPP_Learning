/*
题目：shared_ptr为什么没有release成员？

解答
release()是unique_ptr的成员函数：切断智能指针和内存的关联，返回裸指针，放弃所有权。unique_ptr是独占所有权，所有权只有一份，可以交出所有权。
而shared_ptr是共享所有权，使用引用计数：一块内存可能被多个shared_ptr同时持有。
如果shared_ptr提供release()，语义很难定义：调用release，是放弃当前这一份引用？还是直接交出裸指针、停止引用计数管理？
shared_ptr的设计：放弃所有权只需要销毁 / 赋值覆盖，引用计数自动减一。
shared_ptr没有独占所有权，不存在 “交出唯一所有权” 的场景。
如果拿到裸指针，可以用.get()；shared_ptr不支持把内存管理权从智能指针体系剥离出来。
*/

