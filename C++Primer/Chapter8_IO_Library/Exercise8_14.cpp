/*
目描述：我们为什么将 entry 和 nums 定义为 const auto&？
解答
for (const auto& entry : people)
    for (const auto& nums : entry.phones)
引用 &：避免拷贝对象。entry是PersonInfo，nums是std::string；如果不用引用，每次循环会拷贝整个结构体 / 字符串，产生额外内存开销，效率低。
const：循环内只是读取打印，不会修改元素。使用const引用，明确语义禁止修改；同时可以接收 const 容器，兼容性更好。
auto：自动推导元素类型，不用手写冗长的迭代器 / 对象类型，简化代码。
如果写成auto entry：值拷贝；写成auto &entry：可修改引用，可以修改容器内元素；业务仅读取场景优先const auto&。
核心要点
&防止拷贝提升性能；const表明只读、防止误修改；auto自动推导类型。
*/