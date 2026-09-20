/*
题目描述
在本节最后一个例子中，如果不将insert的结果赋予 begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

本节例子：forward_list首位置插入
auto begin = flst.insert_after(flst.before_begin(), 42);

insert_after返回新插入元素的迭代器。
如果不保存返回值：后续如果拿这个begin去遍历，会直接跳过链表第一个元素；
*/