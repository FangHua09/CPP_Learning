/*
 *编写一个新的 sum 版本，它的返回类型保证足够大，足以容纳加法结果。
 思路：使用尾置返回类型 + decltype，用0 + 元素推导，提升类型容量，或者用decltype拿到加法表达式类型。
 template <typename T>
 auto sum(T a, T b) -> decltype(a + b)
 {
     return a + b;
 }
 原理
 decltype(a+b)得到a 加 b 运算结果的类型，这个类型就是加法运算本身返回的类型，天然足够保存相加结果。
 */
