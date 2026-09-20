/*
调用：i.combine(s)；i是Sales_data对象，s是string。
//(a)
Sales_data &combine(Sales_data);
//(b)
Sales_data &combine(Sales_data&);
//(c)
Sales_data &combine(const Sales_data&) const;

前提：combine 的 string 构造函数未加 explicit，允许隐式转换。
(a) Sales_data &combine(Sales_data);参数是值传递。s(string)隐式转换生成临时Sales_data对象，拷贝传入参数；函数拿到临时副本，可以正常调用。✅合法。
(b) Sales_data &combine(Sales_data&);参数是普通非常量左值引用。临时对象是右值，不能绑定到非 const 左值引用。❌编译报错。
(c) Sales_data &combine(const Sales_data&) const;const 引用可以绑定临时右值。s隐式转换出临时 Sales_data 对象，绑定到 const 引用，调用函数。✅合法。


注意：函数本身标记const，意味着函数内部不能修改i成员；但返回Sales_data&返回非 const 引用是语法缺陷。
如果构造函数是explicit：三种情况都不能隐式转换，都编译报错，必须手动写i.combine(Sales_data(s))。因为仅用户定义的一步转换
*/