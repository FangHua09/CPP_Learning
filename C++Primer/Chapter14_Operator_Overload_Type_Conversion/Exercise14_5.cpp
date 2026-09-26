/*
 *(a) Book
 需要比较书籍、输出信息。重载：==、!=，<<。
 cpp
 bool operator==(const Book&, const Book&);
 bool operator!=(const Book&, const Book&);
 ostream& operator<<(ostream&, const Book&);
 (b) Date
 日期比较大小、相等判断。重载：< <= > >= == !=，<<。
 (c) Employee
 相等比较（工号相同），输出员工信息。重载：==、!=，<<。
 (d) Vehicle
 车辆：相等比较，输出车辆信息。重载：== !=，<<。
 (e) Object
 看用途；如果是通用基类，一般重载 == !=；如果支持函数对象，则重载 operator()。
 (f) Tree
 树结构：视场景；如果需要比较两棵树相等，重载== !=；支持遍历打印则重载<<。
 核心思路：
 只要需要比较对象是否相等：重载==，再用==实现!=。
 需要打印对象信息：重载<<。
 需要大小关系：重载<，其余比较运算符基于<实现。
 */

