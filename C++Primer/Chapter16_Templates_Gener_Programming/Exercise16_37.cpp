/*
 *练习 16.37
 标准库 max 模板只有一个模板类型参数，能否传一个int和一个double？怎么做？不行的话说明原因。
 template<typename T>
 const T& max(const T& a, const T& b);
 直接调用 max(1, 2.5) 不可以。理由：函数两个形参类型都是T，模板实参推断要求两个实参推导出同一个T；int和double是不同类型，推断无法统一，编译报错。
 
 ✅解决办法：显式指定模板实参
 max<double>(1, 2.5);
 显式指定T=double；此时int实参隐式转换为double，可以调用。
 小结：不能直接传；显式模板实参强制T为double，int转为 double。
 */
