/*
 *区分两个转换运算符
 struct Integral {
     operator const int();
     operator int() const;
 };
 
 operator const int();成员函数没有 const 修饰：只能在非 const 对象上调用；返回类型是const int（返回一个 const 值，对于 int 这种内置类型，const int和int几乎没有差别）。
 operator int() const;成员函数后面带const：const 对象、非 const 对象都可以调用；返回普通int。
 重点：const修饰在成员函数后面，修饰的是this 指针，决定能不能在 const 实例调用；写在返回类型前面的const int，是修饰返回值。对于内置 int，返回 const int 几乎无意义。
 推荐写法：operator int() const;，const 成员函数，通用性更好。
 */

