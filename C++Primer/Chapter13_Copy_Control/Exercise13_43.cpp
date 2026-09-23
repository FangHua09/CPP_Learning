/*
题目描述：重写 free 成员，用for_each + lambda代替 for 循环 destroy 元素；对比两种写法偏好。
知识点：for_each遍历范围，lambda 内调用 alloc.destroy。
旧 free：
*/
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

// 类vector内部内存分配策略的实现
class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    // 拷贝构造
    StrVec(const StrVec &orig);

    // 析构
    ~StrVec();

    // 拷贝赋值
    StrVec &operator=(const StrVec &rhs);

    // 新增初始值列表构造函数
    StrVec(initializer_list<string> il);

    // push_back
    void push_back(const string &);

    // begin
    string *begin() const { return elements; }

    // end
    string *end() const { return first_free; }

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    // reserve
    void reserve(size_t n);

    // resize
    void resize(size_t n);

private:
    static allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;

    // 四个工具函数
    // 销毁元素 释放内存
    void free();

    // 获取更多内存并拷贝已有元素
    void reallocate();

    // 将元素范围拷贝到新空间返回pair
    pair<string *, string *> alloc_n_copy(const string *, const string *);

    // 至少能存放一个元素的空间，大于一就新空间翻倍
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
};

// 静态成员类外定义
allocator<string> StrVec::alloc; // 需要加到类外面

// resize
void StrVec::resize(size_t n)
{
    if (n > capacity())
    {
        reserve(n);
        // first_free-cap的空间全部构造空串
        for (auto beg = first_free; beg != elements + n; beg++)
        {
            alloc.construct(beg, string());
        }
    }
    else if (n > size())
    {
        // 那就在first_free-n这个区间构造空串
        for (auto beg = first_free; beg != elements + n; beg++)
        {
            alloc.construct(beg, string());
        }
    }
    else if (n < size())
    {
        // 销毁n - first_free的元素
        for (auto end = first_free; end != elements + n;)
        {
            alloc.destroy(--end);
        }
        // 不要 deallocate！内存保留，capacity不变
    }
    // 更新指针
    first_free = elements + n;
}

// reserve：预分配至少new_cap容量
void StrVec::reserve(size_t n)
{
    if (n > capacity())
    {
        // auto newpair = alloc_n_copy(elements, first_free); 这里不复用 实现完整逻辑
        auto beg = alloc.allocate(n); // 新开辟大小为n的空间
        auto dest = beg;              // 新内存起始
        auto elem = elements;         // 旧内存起始
        for (; elem != first_free;)
        {
            alloc.construct(dest++, move(*elem++));
        }
        free();
        elements = beg;
        first_free = dest;
        cap = elements + n;
    }
}

// 销毁元素 释放内存
void StrVec::free()
{
    if (elements)
    {
        // 从尾删到头
        //
        auto end = first_free;
        for_each(elements, first_free, [](string& s){
            alloc.destroy(&s); // 捕获列表不用写this，因为alloc是静态变量
        });
        // 归还空间
        //`deallocate` 的第二个参数，**必须和 allocate 时传入的字节数（元素个数）一致**。
        alloc.deallocate(elements, cap - elements);
    }
}

// 获取更多内存并移动已有元素
void StrVec::reallocate()
{
    auto newcapacity = (capacity()) ? capacity() * 2 : 1;
    auto newp = alloc.allocate(newcapacity);
    auto dest = newp;
    auto elem = elements;
    for (; elem != first_free;)
    {
        alloc.construct(dest++, move(*elem++));
    }
    // 更新
    elements = newp;
    first_free = dest;
    cap = elements + newcapacity;
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto newp = alloc.allocate(e - b);
    return {newp, uninitialized_copy(b, e, newp)};
}

// 拷贝构造
StrVec::StrVec(const StrVec &orig)
{
    auto newpair = alloc_n_copy(orig.elements, orig.first_free); // 返回的是新空间的orgi的值
    elements = newpair.first;
    first_free = cap = newpair.second;
}

// 析构
StrVec::~StrVec()
{
    free();
}

// 拷贝赋值
StrVec &StrVec::operator=(const StrVec &rhs)
{
    // 先拷贝 避免自赋值
    auto newpair = alloc_n_copy(rhs.begin(), rhs.end());
    // 删除左侧对象的空间
    free();
    // 重新赋值
    elements = newpair.first;
    first_free = cap = newpair.second;
    // 返回对象
    return *this;
}

// initialized初始值列表构造函数
StrVec::StrVec(initializer_list<string> il)
{
    auto capacity = il.size();
    auto beg = alloc.allocate(capacity);
    elements = beg;
    for (auto &&s : il)
    {
        alloc.construct(beg++, s);
    }
    first_free = beg;
    cap = elements + capacity;
}

// push_back
void StrVec::push_back(const string &s)
{
    // 先检查是否至少能容纳一个元素
    check_n_alloc();
    alloc.construct(first_free++, s);
}
