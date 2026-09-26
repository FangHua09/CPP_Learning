/*
 *练习 14.11：找错误
 cpp
 istream& operator>>(istream& in, Sales_data& s)
 {
     double price;
     in >> s.bookNo >> s.units_sold >> price;
     s.revenue = s.units_sold * price;
     return in;
 }
 ❌ 错误点
 没有检查流状态！
 哪怕 in >> 读取失败（例如输入 (b)），代码依然会执行 s.revenue = s.units_sold * price，使用旧的脏数据，破坏对象。
 输入失败时没有重置对象，流失败标志不会被处理。
 对上一题 (b) 输入的表现：
 读到s.units_sold时解析24.95失败，in置为failbit。但是代码继续执行乘法，s.units_sold 保留旧值，revenue 被错误改写，对象处于非法状态。
 对比正确版本：一旦流失败，就把s重置为默认空对象。
 */

