/*
 *template <class T> int compare(const T&, const T&);
 (a) compare("hi", "world");
 ❌ 非法，编译报错
 第一个实参：const char[3]
 第二个实参：const char[6]
 形参是引用，数组不退化，两个实参类型不同，无法推导出统一的 T。
 原因：数组引用的长度是类型的一部分，长度不同就是不同类型，不能匹配同一个 const T&。
 
 (b) compare("bye", "dad");
 ✅ 合法
 两个字符串字面量都是 4 个字符（含 '\0'），类型都是 const char[4]。
 推导出 T = char[4]，两个形参都能匹配 const char(&)[4]。
 */
