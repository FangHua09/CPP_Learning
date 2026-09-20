// find_char 函数原型参考书本：
/*
string::size_type find_char(const string &s, char c, string::size_type &occurs);
*/

/*
三个形参：
const string &s：常量引用
char c：值传递
string::size_type &occurs：普通引用

① s 为什么是常量引用？
s只做读取，函数不修改字符串内容；const保护，防止误修改。
引用避免 string 大对象拷贝，提升性能。

② occurs 为什么是普通引用？
occurs 用来向外返回统计结果（字符出现次数），函数内部要修改它的值，供调用者拿到结果；不能 const。

③ s、occurs 是引用，c 为什么不是引用？
char是很小的内置类型，拷贝开销极低，没必要引用；传值简单高效。

④ 如果 s 改成普通引用 string &s会发生什么？
不能传入字符串字面值、临时 string 对象；
*/