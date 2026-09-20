/*
题目描述：一个容器的 capacity 可能小于它的 size 吗？
解答不可能。capacity 代表已经分配的内存空间，size 是实际元素数目。vector 保证必须有足够内存存放全部 size 个元素，所以一定满足 size() ≤ capacity()。一旦 size 将要超过 capacity，vector 会自动重新分配更大内存。

*/