/*
 *练习 14.14：为什么用 operator+= 来实现 operator+ 更高效？
 Sales_data operator+(Sales_data lhs, const Sales_data& rhs)
 {
     lhs += rhs;
     return lhs;
 }
 原因：
 + 需要返回新对象，必须拷贝左操作数；+= 修改左操作数，不需要额外创建临时对象。
 复用+=的逻辑：代码只需要写一次，维护简单，保证+和+=行为一致。
 参数lhs是传值拷贝：在函数入口就已经生成副本，之后直接在副本上调用+=修改，最后返回这个副本。编译器可以做返回值优化（RVO），减少对象拷贝开销。
 对比坏写法（单独实现 + 和 +=，两份逻辑）：
 // 不推荐，重复代码，容易逻辑不一致
 Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
 {
     Sales_data res;
     res.units_sold = lhs.units_sold + rhs.units_sold;
     res.revenue = lhs.revenue + rhs.revenue;
     return res;
 }
 核心一句话：+是只读运算，要生成新对象；+=就地修改对象。用+=实现+，代码复用，行为统一，拷贝只发生一次。
 */

