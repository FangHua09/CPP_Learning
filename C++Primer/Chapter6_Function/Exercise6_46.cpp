/*
题目：能把 isShorter 函数定义成 constexpr 函数吗？如果能，将它改写成 constexpr 函数；如果不能，说明原因。
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
    
解答❌不能定义为 constexpr 函数。原因：std::string不是字面量类型；string::size()成员函数不是constexpr（C++17 之前），不能在编译期求值。constexpr函数要求所有操作都可以在编译期完成；形参是const string&，string 对象运行期才能构造，无法编译期计算 size。
如果传入的是普通字符串字面量，std::string本身运行时构造，不能用于 constexpr 上下文。
补充：C++20 以后 string 有部分 constexpr 支持，但教材语境下不认为可以写成 constexpr。
*/