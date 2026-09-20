/*
题目描述：为了读取string的list中的元素，应该使用什么类型？如果写入list，又该使用什么类型？
解答容器：std::list<std::string>
读取元素（只读）：list<string>::const_iteratorconst_iterator迭代器，可以读取元素，不能修改元素的值。
写入 / 修改元素：list<string>::iteratoriterator迭代器，既可以读取，也可以修改容器内元素。

注意：list不支持下标访问，只能使用迭代器。

*/