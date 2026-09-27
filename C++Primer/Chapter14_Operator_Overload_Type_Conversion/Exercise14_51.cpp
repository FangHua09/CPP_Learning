/*
 *void calc(int);
 void calc(LongDouble);
 double dval;
 calc(dval); // 哪个calc？
 候选函数：
 calc(int)：double → int，内置转换
 calc(LongDouble)：double → LongDouble，调用构造函数LongDouble(double)（类类型转换）
 重载匹配规则：
 内置转换 和 类类型转换 属于同一等级（都是一次转换），无法分出优劣。
 👉 编译报错，调用二义性。
 补充：如果想消除歧义，需要手动强制转换：
 cpp
 calc(static_cast<int>(dval));      // 调用calc(int)
 calc(LongDouble(dval));           // 调用calc(LongDouble)
 */

