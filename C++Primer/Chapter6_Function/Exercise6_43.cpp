/*
题目：你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);

解答
(a) inline函数定义放在头文件。
内联函数需要在调用点展开，每个用到该函数的编译单元都必须看到完整函数定义；如果放在 cpp 源文件，其他文件看不到函数体，无法做内联展开。头文件提供 inline 完整定义，头文件保护宏防止多重定义。
(b) void putValues(int *arr, int size); 声明放在头文件，函数实现（函数体）放在.cpp源文件。普通非内联函数：头文件放声明供多处调用；源文件放唯一的定义，避免多重定义错误。
规则：inline函数、constexpr 函数完整定义放头文件；普通函数头文件只写声明。
*/