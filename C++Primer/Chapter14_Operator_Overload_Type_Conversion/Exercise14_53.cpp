/*
 *cpp
 SmallInt s1;
 double d = s1 + 3.14;
 SmallInt 类定义（书上）：
 cpp
 class SmallInt {
     friend SmallInt operator+(const SmallInt&, const SmallInt&);
 public:
     SmallInt(int = 0);               // int → SmallInt 转换构造函数
     operator int() const { return val; } // SmallInt → int 类型转换运算符
 private:
     std::size_t val;
 };
 第一步：列出候选 operator+
 自定义非成员：SmallInt operator+(const SmallInt&, const SmallInt&)
 内置运算符集合：所有内置二元 +，包括 operator+(int, double)


 第二步：逐个判断可行函数

 自定义 operator+(const SmallInt&, const SmallInt&)
 表达式s1 + 3.14：
 左：s1 → const SmallInt& 精确匹配
 右：3.14(double) 需要转为SmallInt：double → int（内置），再int → SmallInt（用户自定义转换构造）
 👉 需要一次内置转换 + 一次用户自定义转换，重载调用不允许叠加两次转换，不可行。

 内置 operator+(int, double)
 左：s1 使用 operator int() 做一次用户自定义转换：SmallInt → int
 右：3.14 是 double，精确匹配
 👉 只含一次用户自定义转换，符合规则，可行。

 
 结论
 ✅ 表达式合法，选用内置加法运算符 operator+(int, double)执行流程：
 s1.operator int() 把s1转为 int；
 int 内置提升为 double；
 浮点数加法运算，结果存入d。
 */

