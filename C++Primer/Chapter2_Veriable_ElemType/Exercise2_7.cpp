/*
题目：下述字面值表示何种含义？它们各自的数据类型是什么？

(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L

(a) "Who goes with F\145rgus?\012"：字符串字面值，类型const char[]
\145：八进制转义，字符e；\012：八进制换行符\n。
字符串等价于："Who goes with Fergus?\n"
(b) 3.14e1L：long double，科学计数法 
3.14×10 
1
 =31.4
(c) 1024f：float单精度浮点数 1024。
(d) 3.14L：long double长双精度浮点数 3.14。
*/