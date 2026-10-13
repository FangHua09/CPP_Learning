/*
 *练习 16.31 简答题（考试背诵版）
 问：DebugDelete 和 unique_ptr 一起使用，编译器将删除器处理为内联的原理？
 答案：
 unique_ptr的删除器类型是模板类型参数，在编译期就确定了DebugDelete的类型。
 unique_ptr<T, DebugDelete>，删除器DebugDelete不是保存在运行期堆中，而是类型层面绑定；
 DebugDelete::operator()是普通成员函数，编译期完全可知；
 编译器知道析构时调用的是哪一个operator()，可以直接把函数体（delete p）内联展开，省去函数调用开销。
 对比：shared_ptr删除器保存在运行期控制块，类型运行期才确定，无法内联。
 */
