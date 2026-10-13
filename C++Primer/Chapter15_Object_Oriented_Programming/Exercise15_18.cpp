/*
 *前置类定义（书上 543 页）
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
 练习 15.18 判断赋值合法性
 cpp
 Base *p = &d1;    // d1: Pub_Derv
 p = &d2;          // d2: Priv_Derv
 p = &d3;          // d3: Prot_Derv
 p = &dd1;         // dd1: Derived_from_Public
 p = &dd2;         // dd2: Derived_from_Private
 p = &dd3;         // dd3: Derived_from_Protected
 Base *p = &d1; ✅ 合法
 Pub_Derv是public Base，公有继承，外部允许派生类→基类指针转换。
 p = &d2; ❌ 非法
 Priv_Derv是private Base。私有继承，外部代码不能把 Priv_Derv隐式转为 Base。Base 变成 Priv_Derv 的私有基类，外部不可访问。
 p = &d3; ❌ 非法
 Prot_Derv是protected Base。保护继承，外部代码不能把 Prot_Derv隐式转为 Base。Base 变成 Prot_Derv 的保护基类，外部不可访问。
 p = &dd1; ✅ 合法
 Derived_from_Public公有继承Pub_Derv，Pub_Derv 又是 public Base。继承链为公有的，外部依然可以隐式转 Base*。
 p = &dd2; ❌ 非法
 Derived_from_Private公有继承 Priv_Derv，而 Priv_Derv 私有继承 Base。Base 对于 Priv_Derv 及其后代来说是私有基类，外部不可访问。
 p = &dd3; ❌ 非法
 Derived_from_Protected公有继承 Prot_Derv，Prot_Derv 保护继承 Base。Base 对于 Prot_Derv 及其后代是保护基类，外部不可访问。
 一句话总结：只有整条继承链都是 public，外部才能把派生类地址赋值给 Base*。
 */
