/*
如果string 版本构造函数和istream & 版本构造函数都带上默认实参，合法吗？
Sales_data(const std::string &s = "");
Sales_data(std::istream &is = std::cin);

不合法，会产生二义性。
当执行：Sales_data data;编译器不知道调用哪一个构造函数：

可以调用第一个：默认参数空字符串；
也可以调用第二个：默认参数cin。
两个构造函数都可以无参调用，出现函数调用二义性，编译报错。
*/