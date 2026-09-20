/*
练习 6.39
题目描述：说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明，请指出来。
(a)
int calc(int, int);
int calc(const int, const int);

(b)
int get();
double get();

(c)
int *reset(int *);
double *reset(double *);

(a) 分析
int calc(int, int);
int calc(const int, const int);
第二条：形参是两个const int。
对于值参数，顶层 const 不影响函数签名。int和const int作为值形参，编译器视为同一个函数。两条声明是同一个函数的重复声明，不是重载，合法，但不能定义两个版本。函数调用传入普通 int，既可以匹配第一条也可以匹配第二条，二者没有重载区分效果。
原理：值传递，实参拷贝给形参，形参是否 const 只影响函数内部能不能修改形参，对外接口没有区别。

(b) 分析
int get();
double get();
第二条返回double，形参列表为空。❌ 非法，不能构成重载。函数重载只看形参列表，不看返回值。仅返回值不同，编译器无法区分调用哪一个，编译报错。

(c) 分析
int *reset(int *);
double *reset(double *);
第二条：参数是double*，返回double*。✅ 合法函数重载。形参类型不一样（int* vs double*），形参列表不同，可以构成重载；调用时根据传入指针实参类型匹配对应版本。

总结
(a)：不是重载，只是重复声明，顶层 const 值形参不参与重载；
(b)：非法；仅返回值不同不能重载；
(c)：合法重载；指针形参类型不同。
核心知识点
C++ 函数重载判定规则：只看形参列表（数量、类型、顺序）；返回类型不作为重载依据；值形参的顶层 const 不区分重载。
*/