/*
 *是否应该定义上面两个转换运算符？是否应该加explicit？为什么？✅ 不建议定义这两个隐式类型转换运算符。原因：
 一个Sales_data对象隐式转string或者double含义模糊。编译器会在很多意外场景自动触发隐式转换，造成难以发现的 bug。例如直接把Sales_data对象传给接收string或double的函数，编译器自动转换，很容易写错。
 如果一定要提供这两个转换，必须加上explicit，禁止隐式转换，只能手动强制类型转换：
 cpp
 explicit operator std::string() const { return bookNo; }
 explicit operator double() const { return revenue / units_sold; }
 加上explicit后，只能用 static_cast<string>(sd)，不能自动隐式转换。
 最佳实践：尽量避免定义类型转换运算符。如果一定要写，一律explicit。
 */

