/*
练习 7.47
Sales_data 接收单个string的构造函数是否应该explicit？
cpp
运行
Sales_data(const std::string &s);
应该定义为explicit
cpp
运行
explicit Sales_data(const std::string &s);

✅优点：
禁止隐式类型转换：不会自动把string隐式转换成Sales_data对象，避免意外隐式转换带来 bug。
例如函数接收Sales_data形参，不会误传一个string就自动构造临时对象。
代码可读性更好，对象转换必须显式写出，意图明确。

❌缺点：
不能拷贝形式直接初始化：不能Sales_data item = "xxx";这种拷贝初始化写法；只能直接初始化Sales_data item("xxx");。
需要转换的时候，必须手动显式转换Sales_data("xxx")，写代码稍微麻烦一点。
总结：业务语义上，string 书本编号不等于 Sales_data 对象，不应该自动隐式转换，所以适合 explicit。
*/