/*
题目描述：编写简化 String 类，至少默认构造 + C 风格字符串指针构造，使用 allocator 分配内存。
知识点：allocator 分配原始内存；strlen获取 C 字符串长度；construct原地构造。
*/
#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

class String
{
public:
    String() : elements(nullptr), end(nullptr) {}
    String(const char *c_str);

private:
    static allocator<char> alloc;
    char *elements;
    char *end;
};

allocator<char> String::alloc; // 类外，全局作用域下定义静态成员

String::String(const char *c_str)
{
    size_t len = strlen(c_str);
    elements = alloc.allocate(len + 1);
    auto beg = elements;
    for (; beg != elements + len; beg++)
    {
        alloc.construct(beg, c_str[beg - elements]);
    }
    alloc.construct(beg, '\0');
    end = elements + len + 1; // 指向'\0'后一个位置
}