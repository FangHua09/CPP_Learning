/*
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");

①构造函数不是 explicit（普通单参数构造）
item1(null_isbn)：直接初始化，调用Sales_data(const string&)构造函数。
item2("9‑999‑99999‑9")：字符串字面量先转为string临时对象，再调用构造函数直接初始化。
两条语句都合法，正常构造对象。

②构造函数是 explicit
explicit只限制拷贝初始化，不限制直接初始化。
Sales_data item1(null_isbn);   // ✔直接初始化，合法
Sales_data item2("9-999-99999-9"); // ✔直接初始化，合法

以上两行依旧正常编译运行。
explicit 禁止：Sales_data item = null_isbn;这种拷贝初始化形式，不禁止括号直接初始化。
*/