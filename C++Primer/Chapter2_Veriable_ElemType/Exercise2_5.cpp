/*
**题目**：指出下述字面值的数据类型并说明每一组内几种字面值的区别：
(a) `'a'`, `L'a'`, `"a"`, `L"a"`
(b) `10`, `10u`, `10L`, `10uL`, `012`, `0xC`
(c) `3.14`, `3.14f`, `3.14L`
(d) `10`, `10u`, `10.`, `10e‑2`

(a)
'a'：char，普通字符字面值
L'a'：wchar_t，宽字符字面值
"a"：const char[2]，字符串字面值（'a' + 末尾'\0'）
L"a"：const wchar_t[2]，宽字符串字面值

10：int，十进制整数
10u：unsigned int，十进制无符号整数
10L：long，十进制 long 长整数
10uL：unsigned long，十进制无符号 long
012：int，八进制，等价十进制 10
0xC：int，十六进制，等价十进制 12

3.14：double双精度浮点
3.14f：float单精度浮点
3.14L：long double长双精度浮点

10：int整型
10u：unsigned int无符号整型
10.：double浮点（小数点代表浮点数）
10e‑2：double科学计数法
*/