/*
题目描述：begin 和 cbegin 两个函数有什么不同？

解答
begin()：返回普通迭代器（iterator）。
如果容器是非 const，begin()得到iterator，可读可修改元素。
如果容器是const，begin()返回const_iterator，只能读。
cbegin()（C++11 新增）：永远返回 const_iterator，不管容器本身是否 const。只能读取元素，禁止修改。

简单总结：
begin()：迭代器类型由容器是否 const 决定；
cbegin()：强制返回常量迭代器，用于只读访问。

*/