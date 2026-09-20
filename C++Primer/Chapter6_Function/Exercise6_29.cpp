/*
题目描述：在范围 for 循环中使用 initializer_list 对象时，应该将循环控制变量声明成引用类型吗？为什么？
解答不建议使用普通引用auto &elem；可以使用const auto &elem，也可以直接值auto elem。
initializer_list内部的元素都是const，普通非常量引用auto& elem会编译报错，不能修改列表里的元素。
const auto &elem：避免拷贝元素，适合元素类型较大（string 等）。
auto elem：值拷贝，如果是 int 等小型内置类型开销很小，写法简单。
总结：优先 const auto &elem；内置小类型直接auto elem；禁止普通非常量引用。
*/