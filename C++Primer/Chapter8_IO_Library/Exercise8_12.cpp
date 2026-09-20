/*
题目描述：我们为什么没有在 PersonInfo 中使用类内初始化？
解答
struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};
该结构体是聚合类，用于保存运行时读取的数据；姓名、电话号码都是程序运行时输入得到，编译期没有固定初始值，类内初始值没有实际意义。
std::string、std::vector自带默认构造函数；变量创建时自动初始化为空字符串、空 vector，不需要手动指定类内初始值。
如果增加类内初始值，会改变聚合类性质，无法使用聚合初始化语法。
核心要点聚合类，运行时才确定成员值，string/vector 自带默认初始化。
*/