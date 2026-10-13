/*
 *实现代码，打印身份信息
 */
#include <iostream>
using namespace std;

template <typename T>
void f(T)
{
    cout << "【f(T)通用模板】\n";
}
template <typename T>
void f(const T *)
{
    cout << "【f(const T*)指针模板】\n";
}

template <typename T>
void g(T)
{
    cout << "【g(T)通用模板】\n";
}
template <typename T>
void g(T *)
{
    cout << "【g(T*)指针模板】\n";
}

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    cout << "==== g系列 ====\n";
    g(42);
    g(p);
    g(ci);
    g(p2);

    cout << "\n==== f系列 ====\n";
    f(42);
    f(p); // 【f(T)通用模板】 可以精确匹配 不需要额外加一步const
    f(ci);
    f(p2);
    return 0;
}
/*
【g(T)通用模板】
【g(T*)指针模板】
【g(T)通用模板】
【g(T*)指针模板】

==== f系列 ====
【f(T)通用模板】
【f(T)通用模板】
【f(T)通用模板】
【f(const T*)指针模板】
*/