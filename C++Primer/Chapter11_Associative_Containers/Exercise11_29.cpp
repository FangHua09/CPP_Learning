/*
题目描述：如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？
知识点：有序关联容器的范围查找函数；三个函数均基于有序 key。
解答：
设查找目标为 key，容器有序。key 不存在：
lower_bound(key)：返回第一个大于 key的元素迭代器；若所有元素都小于 key，返回end()。
upper_bound(key)：返回第一个大于 key的元素迭代器；和上面 lower_bound 结果相同。

equal_range(key)：返回pair，两个迭代器都等于 lower_bound 的结果，即make_pair(lower_bound(key), lower_bound(key))。
含义：目标 key 所在区间为空，区间起点终点重合。
*/
