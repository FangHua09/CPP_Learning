/*

可以定义一个 vector<int>::iterator 到 int 的 map 吗？list<int>::iterator 到 int 的 map 呢？对于两种情况，如果不能，解释为什么。
map<vector<int>::iterator, int>：可以，随机迭代器支持 <
map<list<int>::iterator, int>：不可以，双向迭代器不支持小于比较，map 需要 key 能使用<排序。

一句话总结：map 的 key 必须能用<比较；vector 迭代器是随机访问迭代器，支持<；list 迭代器是双向迭代器，不支持<。
*/
