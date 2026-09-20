/*
练习 7.51
vector单参数构造是explicit；string单参数构造不是 explicit。
vector(size_type n)：用数字 n 创建 n 个元素。

vector<int> v = 10; // 如果不explicit：把int隐式转vector<int>，语义荒谬，没有业务意义。
数字不是 vector 对象，不允许隐式转换，所以加explicit。

string(const char*)：C 风格字符串char*天然就表示字符串；业务场景非常频繁需要const char*→std::string自动转换，这种隐式转换是符合业务直觉、方便编程，所以不设置 explicit。
核心判断：如果参数类型在语义上不等于本类对象，就用 explicit 禁止隐式转换；如果参数天然就代表本类语义，则允许隐式转换。

*/