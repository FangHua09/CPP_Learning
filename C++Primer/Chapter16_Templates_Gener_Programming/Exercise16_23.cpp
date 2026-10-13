/*
 *练习 16.23：预测何时执行 DebugDelete 的调用运算符
 预测
 当 shared_ptr 的引用计数变为 0，要释放底层管理的对象时，会执行 DebugDelete 的 operator()。
 也就是：
 TextQuery 对象销毁时；
 TextQuery 对象被赋值，原来的 shared_ptr 被覆盖，旧资源引用计数归零；
 shared_ptr 调用 .reset()，放弃管理原有指针。
 实际执行时机
 当TextQuery局部变量离开作用域，file成员销毁，shared_ptr的引用计数减到 0，此时调用删除器，执行DebugDelete::operator()。
 注意：不是 shared_ptr 对象本身销毁就立刻调用，只有引用计数 == 0 的时候才会调用删除器的 () 运算符。
 */
