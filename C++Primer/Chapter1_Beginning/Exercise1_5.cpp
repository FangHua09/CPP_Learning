// 练习 1.5：拆分成多条独立输出语句
#include <iostream>
int main()
{
    int v1, v2;
    std::cin >> v1 >> v2;

    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}

// 解析：`<<` 返回流对象，既可以链式写一行，也可以分开多条语句执行输出。