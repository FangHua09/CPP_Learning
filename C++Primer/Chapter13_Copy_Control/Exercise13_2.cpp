/*
问：解释为什么 Sales_data::Sales_data(Sales_data rhs); 非法拷贝构造函数的参数不能是值传递，只能是引用。
如果参数是Sales_data rhs（传值），调用这个构造函数时，需要把实参拷贝给形参rhs；
拷贝实参又需要调用拷贝构造函数，无限递归，编译报错。
所以拷贝构造函数必须用引用参数：Sales_data::Sales_data(const Sales_data &rhs);
*/
