/*
C++ 的迭代器一共分为 5 类，各类支持的操作如下：
输入迭代器（input iterator）
只读，单遍扫描（只能遍历一次）。
支持：==、!=、++（前置 / 后置）、*（解引用，只能读）、->。
例子：istream_iterator。

输出迭代器（output iterator）
只写，单遍扫描。
支持：++（前置 / 后置）、*（解引用，只能写）。
例子：ostream_iterator、back_inserter。

前向迭代器（forward iterator）
可读写，多遍扫描，可以保存迭代器状态。
支持输入 + 输出迭代器的全部操作。
例子：forward_list 的迭代器。

双向迭代器（bidirectional iterator）
在前向迭代器基础上，支持递减操作 --（可以向前移动）。
例子：list、map、set 的迭代器。

随机访问迭代器（random-access iterator）
在双向迭代器基础上，支持：+n、-n、+=、-=、下标[]、关系运算符<、>、<=、>=。
例子：vector、string、array 的迭代器。
*/