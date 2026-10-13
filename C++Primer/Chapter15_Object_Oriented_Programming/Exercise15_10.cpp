/*
 *解释将ifstream传递给Sales_data的read函数是如何工作的。
 cpp
 // read函数原型
 istream& read(istream &is, Sales_data &item);
 ifstream是istream的派生类；istream是基类。
 read的第一个形参是istream&（基类引用）。
 根据继承规则：基类引用可以绑定派生类对象。
 静态类型：istream&；动态类型：ifstream。
 当 read 内部调用is >> item时，>>是istream定义的虚函数体系，动态绑定，实际调用ifstream的输入操作，从文件读取数据。
 */
