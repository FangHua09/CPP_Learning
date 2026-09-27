/*
 *练习 14.50
 cpp
 struct LongDouble {
     LongDouble(double = 0.0);
     operator double();
     operator float();
 };
 LongDouble ldObj;
 int ex1 = ldObj;
 float ex2 = ldObj;
 int ex1 = ldObj;
 转换候选：
 ldObj → double（operator double()），再double → int（内置转换）
 ldObj → float（operator float()），再float → int（内置转换）
 结果：编译报错，二义性
 两个转换路径都只包含一次类类型转换 + 一次内置转换，优先级完全相同，编译器无法选出最佳匹配。
 float ex2 = ldObj;
 候选：
 ldObj → float，直接调用 operator float()
 ldObj → double，再double → float内置转换
 结果：合法，选用 operator float()
 第 1 条路径只需要一次类类型转换；第 2 条是类转换 + 内置转换。
 只需要一次转换的版本更好，没有歧义。
 小结：
 int ex1 = ldObj; ❌ 二义性，编译失败
 float ex2 = ldObj; ✅ 调用 operator float()
 */

