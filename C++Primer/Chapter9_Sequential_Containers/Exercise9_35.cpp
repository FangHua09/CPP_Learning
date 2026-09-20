/*
题目描述：解释一个 vector 的 capacity 和 size 有何区别。
解答
size()：返回容器中实际保存的元素个数。
capacity()：返回不重新分配内存的前提下，vector最多能够容纳的元素总数，代表已经分配好的内存空间大小。
size ≤ capacity。
size是已经构造出来的有效对象数量；capacity是内存容量，包含还未构造对象的剩余内存。
知识点总结size：已存在元素数量；capacity：分配的总内存可容纳元素上限。

*/