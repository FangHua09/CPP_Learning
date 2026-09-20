/*
7.5.5 节的 Data 类是字面值常量类吗？
教材 Data 类：
struct Data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

不是字面值常量类。
字面值常量类要求：所有数据成员都必须是字面值类型。std::string不是字面值类型，因此哪怕是聚合类，Data 也不是字面值常量类。
补充字面值常量类两条判定规则（C++11，教材标准）：

聚合类版本：是聚合类，全部数据成员都是字面值类型 → 字面值常量类。

非聚合类版本：
所有数据成员都是字面值类型
至少有一个constexpr构造函数
类内初始值必须是常量表达式
数据成员都必须是 public
*/