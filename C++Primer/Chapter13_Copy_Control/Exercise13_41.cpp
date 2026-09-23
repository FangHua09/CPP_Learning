/*
题目描述：push_back 里alloc.construct(first_free++, s)为什么用后置递增？如果前置递增会发生什么？
知识点：后置递增p++：返回原始值，p 自增；前置++p返回自增之后的值。
原代码：alloc.construct(first_free++, s);
含义：拿first_free当前地址原地构造对象，之后first_free 向后移动。
如果写++first_free：先把指针 + 1，再在 + 1 后的地址构造对象，第一个位置永远空着，元素会写到错误位置，内存越界。
✅ 一句话总结：
first_free++：使用当前地址构造，构造完成指针后移。
++first_free：指针先 + 1，在空一格的位置构造，elements [0] 永远不构造，内存错乱。
*/
