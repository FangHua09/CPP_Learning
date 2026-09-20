

/*
编写代码分别更改指针的值以及指针所指对象的值。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <numeric>
#include <bitset>
#include <climits>

int main(int argc, char const *argv[])
{
    // > 编写代码分别更改指针的值以及指针所指对象的值。
    int i = 20;
    int j = 30;
    int *p = &i; // p指向i
    std::cout << *p << '\n';

    //改变指针指向
    p = &j;
    std::cout << *p << '\n';

    //改变指针的值
    *p = 666;
    std::cout << *p << '\n';
    return 0;
}
