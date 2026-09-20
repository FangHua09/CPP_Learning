/*
下面哪些句子是合法的？如果有不合法的句子，请说明为什么？

(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;

(a) const int buf; 非法
const常量必须定义时初始化，之后不能赋值修改。这里没有初始化，编译报错。

(b) int cnt = 0; 合法
普通 int 变量，初始化为 0。

(c) const int sz = cnt; 合法
sz是const int，定义时用变量cnt的值完成初始化。运行期初始化，C++ 允许。此时sz的值为 0，之后不能修改。

(d) ++cnt; ++sz;
++cnt;：合法，普通 int 可以自增。
++sz;：非法，sz是const int常量，不能修改，自增会修改其值，编译报错。

✅总结：合法：(b)、(c)非法：(a) const 未初始化；(d) 中++sz试图修改 const 常量。
*/