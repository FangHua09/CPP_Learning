/*
Debug 中以set_开头的成员应该被声明成constexpr吗？如果不，为什么？
不应该声明为constexpr。
set_io、set_hw、set_other函数要修改类的数据成员。
C++11 标准：constexpr成员函数隐式是const，不允许修改对象状态。修改成员的函数不能是constexpr。
constexpr函数用于编译期求值、不修改对象的场景；set 函数是运行时修改标志，语义不匹配。
*/