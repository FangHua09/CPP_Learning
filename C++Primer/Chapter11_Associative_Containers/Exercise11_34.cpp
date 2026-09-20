/*
题目描述：如果将 transform 函数中的find替换为下标运算符，会发生什么情况？知识点：const map不能使用下标运算符；[]会自动插入不存在的 key，修改 map。解答原代码：auto map_it = m.find(s);如果改成 return m[s];
transform参数的map是const 引用，map的下标运算符[]会在 key 不存在时插入新元素，会修改 map，const map 不支持下标，编译报错。
就算去掉 const：单词不存在时，m[s]会把这个单词作为 key 插入 map，新增一条映射，污染转换表。
结论：不能替换，要么编译失败，要么会插入大量无用键值对。
*/
