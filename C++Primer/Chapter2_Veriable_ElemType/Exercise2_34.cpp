#include <iostream>
int main()
{
    int i = 0;
    const int ci = i, &cr = ci;
    auto a = i;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    std::cout << "赋值前：a=" << a << " b=" << b << " c=" << c << std::endl;
    a = 42;
    b = 42;
    c = 42;
    //d = 42;  //编译报错
    //e = 42;  //编译报错
    //g = 42;  //编译报错
    std::cout << "赋值后：a=" << a << " b=" << b << " c=" << c << std::endl;
    return 0;
}
