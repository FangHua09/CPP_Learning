/*
HasPtr 赋值：hp = hp2; hp = std::move(hp2);
背景：HasPtr 实现了拷贝构造、移动构造；赋值运算符重载：operator=(const HasPtr&)（拷贝赋值），operator=(HasPtr&&)（移动赋值）

hp = hp2;
hp2是左值，匹配拷贝赋值运算符。
参数rhs（形参const HasPtr&）绑定左值 hp2；rhs是 hp2 的别名。
赋值运算符内部：分配新内存，拷贝 hp2 的 string 到 hp；释放 hp 原来的资源。
hp2 全程不变。

hp = std::move(hp2);
std::move(hp2)把 hp2 强制转为右值引用，匹配移动赋值运算符。
参数rhs类型HasPtr&&，绑定到右值引用（指向 hp2）。
接管rhs（hp2）底层 string 指针，hp 拿到资源；hp2 的底层指针被置空，hp2 变成有效但可析构的空对象。
总结：
左值 → 拷贝赋值，hp2 不变；
move 转为右值 → 移动赋值，hp2 资源被夺走。
*/
