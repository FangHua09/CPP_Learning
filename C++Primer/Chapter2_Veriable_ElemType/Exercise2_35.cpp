/*
auto 类型推导
const int i = 42; // int
auto j = i; //int
const auto &k = i; // const int&
auto *p = &i; // const int * 保留底层const
const auto j2 = i, //const int
&k2 = i; // const int &

1. auto **忽略顶层 const、忽略引用**；
2. **底层 const 保留**（const 对象取地址）；
3. 自己写`const auto`可以手动加上顶层 const。
4, 自己写auto & 可以保留顶层常量属性，即最终成为常量引用
*/

#include <iostream>
#include <typeinfo>
int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
    return 0;
}
