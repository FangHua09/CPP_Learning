/*
 *练习 16.35
 template <typename T> T calc(T, int);
 template <typename T> T fcn(T, T);
 double d; float f; char c;
 
 (a) calc(c, 'c'); ✅合法第一个实参char，推导出T=char；第二个形参固定为int，'c'（char）隐式转为 int。
 (b) calc(d, f); ✅合法第一个实参double，推导出T=double；第二个形参是 int，float f隐式转换为 int。
 (c) fcn(c, 'c'); ✅合法两个实参都是char，T = char。fcn两个形参都是T，类型匹配。
 (d) fcn(d, f); ❌非法第一个实参double，第二个float。fcn两个形参共用同一个模板参数T。模板推断不会自动把 float 转成 double，编译器无法确定 T，二义性，编译报错。
 */
