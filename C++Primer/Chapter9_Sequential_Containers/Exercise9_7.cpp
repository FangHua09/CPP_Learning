/*
题目描述：为了索引int的vector中的元素，应该使用什么类型？
解答索引vector<int>元素，下标类型是 vector<int>::size_type。

说明：
vector的下标运算符[]的下标参数类型为容器定义的size_type，它是无符号整数类型。
不要直接用int，int是有符号，容器大小可能超出 int 范围；也不要用size_t，优先使用容器自带的size_type，泛用性更好。
*/