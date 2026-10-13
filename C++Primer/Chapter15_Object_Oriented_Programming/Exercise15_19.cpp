/*
 * *前置类定义（书上 543 页）
 class Base {
 public:
     int pub_mem;
 protected:
     int prot_mem;
 private:
     int pri_mem;
 };

 // 三个直接派生类
 class Pub_Derv : public Base { };
 class Priv_Derv : private Base { };
 class Prot_Derv : protected Base { };

 // 第二层派生
 class Derived_from_Public : public Pub_Derv { };
 class Derived_from_Private : public Priv_Derv { };
 class Derived_from_Protected : public Prot_Derv { };

 核心规则：只有 public 继承，外部代码才允许派生类指针 / 对象隐式转换为基类 Base 指针；
 private /protected 继承，外部不能转换。
 派生类内部、友元不受这个限制。

 练习 15.19：void memfcn(Base &b) { b = *this; } 在每个类里是否合法
 b = *this：把当前派生类对象*this隐式转换成 Base，赋值给 Base 引用 b。规则：这条语句写在派生类内部，不是外部！ 在类内部，派生类可以访问基类，不管是 public/private/protected 继承。
 Pub_Derv : public Base ✅合法
 类内，*this可以隐式转 Base&。
 Priv_Derv : private Base ✅合法
 在 Priv_Derv 类内部，私有继承不影响类内访问基类，*this可转 Base&。（只是类外不行）
 Prot_Derv : protected Base ✅合法
 类内部，保护继承，*this可转 Base&。
 Derived_from_Public : public Pub_Derv ✅合法
 继承链公有，类内可转换。
 Derived_from_Private : public Priv_Derv ❌非法
 Priv_Derv 私有继承 Base，Base 对于 Derived_from_Private 是私有成员，在 Derived_from_Private 内部，不能把*this隐式转为 Base。
 Derived_from_Protected : public Prot_Derv ✅合法
 Prot_Derv 保护继承 Base，Base 对于 Derived_from_Protected 是 protected，类内部可以转换。
 */
