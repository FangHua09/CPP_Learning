#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
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
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

class String
{
public:
    String() : elements(nullptr), end(nullptr) {}

    // 析构
    ~String();

    // 拷贝构造
    String(const String &orig);

    // 拷贝赋值
    String &operator=(const String &rhs);

    // 移动构造 (不要加const)
    String(String &&orig);

    // 移动赋值 (不要加const)
    String &operator=(String &&rhs);

    size_t size() const { return end - elements; }

    String(const char *c_str);

private:
    static allocator<char> alloc;
    void free();
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

String::String(const String &orig)
{
    cout << "【拷贝构造函数】" << endl;
    // 左运算对象要有新空间
    auto len = orig.size();
    elements = alloc.allocate(len + 1);
    end = elements + len;
    // 逐份拷贝
    auto last = uninitialized_copy(orig.elements, orig.end, elements);
    /*
    或者循环写法
    auto dest = elements;
    for (size_t i = 0; i < len; ++i)
    {
        alloc.construct(dest++, orig.elements[i]);
    }
    */
    alloc.construct(last, '\0');
}
String &String::operator=(const String &rhs)
{
    cout << "【拷贝赋值运算符】" << endl;
    // 处理自赋值
    if (this == &rhs)
    {
        return *this;
    } // 这里不可以写rhs != *this, 因为String没有定义！=， 而指针支持==
    // 先拷贝右侧的值
    auto len = rhs.size();
    auto newp = alloc.allocate(len + 1);
    auto last = uninitialized_copy(rhs.elements, rhs.end, newp);
    /*
    uninitialized_copy(rhs.elements, rhs.end, newp) 只拷贝 [elements, end) 左闭右开区间，不包含末尾的 '\0'！
    你的 String 类：end 指向最后一个有效字符的后一位，不是 '\0' 的位置。
    rhs.elements ~ rhs.end：存的是真正的字符串字符，不含 \0。\0 是我们单独放在 end 位置的哨兵。

    拷贝赋值运算符必须处理自赋值，用对象地址判断。
    allocator 内存：destroy销毁对象，deallocate归还内存，顺序不能颠倒。
    先分配新内存，再释放旧内存，防止异常导致原对象被破坏。
    uninitialized_copy：只拷贝[first,last)区间，不包含 end 位置的 '\0'，需要单独 construct。
    */
    alloc.construct(last, '\0');
    // 销毁左侧运算对象
    // delete elements; // 错误 alloc分配的需要destroy + deallocate
    // delete end;
    auto p = elements;
    while (p != end)
    {
        alloc.destroy(p++);
    }
    alloc.destroy(end); // 单独销毁末尾'\0'
    alloc.deallocate(elements, end - elements + 1);
    // 赋值
    elements = newp;
    end = last; // end指向有效字符的后一位，即'\0'
    return *this;
}
String::~String()
{
    if (elements)
    {
        cout << "【析构函数】" << '\n';
        free();
    }
}

void String::free()
{
    auto p = elements;
    while (p != end)
    {
        alloc.destroy(p++);
    }
    alloc.destroy(end);                             // 单独销毁末尾'\0'
    alloc.deallocate(elements, end - elements + 1); // 顺便把'\0'的空间也归还了
}

// 移动构造
String::String(String &&orig)
{
    elements = orig.elements;
    end = orig.end;
    orig.elements = orig.end = nullptr;
}

// 移动赋值
String &String::operator=(String &&rhs)
{
    if(this == &rhs) return *this;
    free();
    elements = rhs.elements;
    end = rhs.end;
    rhs.elements = rhs.end = nullptr;
    return *this;
}