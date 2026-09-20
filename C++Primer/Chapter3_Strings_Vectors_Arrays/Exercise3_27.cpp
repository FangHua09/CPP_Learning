/*
假设 txt_size() 是无参函数，返回int。判断下面哪些数组定义非法，说明原因。
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";

(a) 非法C++ 中数组的维度必须是常量表达式。buf_size是普通 unsigned 变量，不是编译期常量，不能用作数组大小。（C 语言变长数组 VLA 是扩展，标准 C++ 不支持）
(b) 合法4*7‑14 = 14，是编译期就能算出的常量表达式；数组大小为 14。
(c) 非法txt_size()是函数调用，运行时才得到返回值，不是编译期常量，不能作为数组维度。
(d) 非法字符串字面量 "fundamental"：字符数 11，末尾还需要存'\0'结束符，一共需要 12 字节空间；数组只给了 11，放不下结束符，数组越界。
"fundamental"：f‑u‑n‑d‑a‑m‑e‑n‑t‑a‑l →11 个字符 + \0 →总共 12。
*/