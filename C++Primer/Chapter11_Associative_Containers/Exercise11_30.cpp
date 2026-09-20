/*
目描述：对于本节最后一个程序中的输出表达式，解释运算对象 pos.first->second 的含义。
知识点：equal_range 返回pair<迭代器,迭代器>；pos.first是区间起始迭代器；map 迭代器指向pair<const key_type, mapped_type>。
解答：
pos：equal_range返回的pair，pos.first是匹配区间的起始迭代器。
pos.first是 multimap 迭代器，指向容器内pair<const string, string>元素。
pos.first->second：取出该键值对的value 部分（作者对应的书名）。
*/
