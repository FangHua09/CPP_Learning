/*
 *练习 16.39
 原始版本 compare：template <class T> int compare(const T&, const T&);使用显式模板实参，可以传递两个字符串字面量。
 原始版本：
 template <class T> int compare(const T&, const T&);
 直接写compare("hi", "world")非法，因为const T&引用形参，数组不退化；"hi"是const char[3]，"world"是const char[6]类型不一致。
 
 ✅显式指定模板实参，强制T = const char*：
 compare<const char*>("hi", "world");
 解释：显式指定T=const char*，不再做模板实参推断。此时形参类型变成 const const char* &（等价const char* const &）。字符串字面量数组会退化为const char*指针，两个实参都匹配const char*，调用合法。
 */
