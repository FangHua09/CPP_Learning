/*
 *练习 16.28：手写简易 shared_ptr、unique_ptr（模板实现，教材要求最简版本）
 核心要点：
 shared_ptr：带引用计数，计数单独在堆上；拷贝构造 / 拷贝赋值递增计数；析构计数减 1，计数到 0 释放资源 + 计数。
 unique_ptr：独占所有权，禁止拷贝；只支持移动；析构直接释放指针。

 SharedPtr
 两个成员：T*指向资源；size_t* ref_cnt在堆上存放引用计数。
 拷贝构造 / 拷贝赋值：共享资源，引用计数 + 1。
 析构：计数减 1；计数归零，释放资源指针 + 释放计数指针。
 重载*、->；支持use_count()查看计数。

 UniquePtr
 持有裸指针；删除拷贝构造、拷贝赋值，只允许移动语义。
 析构直接 delete 裸指针。
 重载*、->、reset()。
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
template <typename T>
class SharedPtr
{
public:
    friend void swap(SharedPtr &lhs, SharedPtr &rhs) noexcept
    {
        std::swap(lhs.p, rhs.p);
        std::swap(lhs.ref_cnt, rhs.ref_cnt);
    }

    SharedPtr() : p(nullptr), ref_cnt(new size_t(0)) {}
    explicit SharedPtr(T *p) : p(p), ref_cnt(new size_t(1)) {}

    // 拷贝构造
    SharedPtr(const SharedPtr &orig)
    {
        /*
        shared_ptr语义：多个智能指针共享同一个 T 对象，不新建对象
        你这里new T(orig.p)：把orig.p这个指针拿去构造 T。
        如果 T 是 int：new int(orig.p)，把指针地址值当成 int 存进去，不是 42！
        完全破坏共享语义，use_count 虽然数字会涨，但两个 sp 指向两块完全不同堆内存。
        */
        // p = new T(orig.p);
        p = orig.p;
        ref_cnt = orig.ref_cnt;
        ++(*ref_cnt);
    }
    // 拷贝赋值
    SharedPtr &operator=(SharedPtr rhs)
    {
        // if (&rhs == this)
        // {
        //     return *this;
        // }
        // auto newp = new T(rhs.p);
        // if (--*ref_cnt == 0)
        // {
        //     delete p;
        //     delete ref_cnt;
        // }
        // // delete p;
        // p = newp;
        // // delete ref_cnt;
        // ref_cnt = rhs.ref_cnt;

        // ++*ref_cnt;

        // 拷贝并交换
        swap(*this, rhs);

        return *this;
    }

    // 移动构造
    SharedPtr(SharedPtr &&orig) noexcept
    {
        p = move(orig.p);
        ref_cnt = move(orig.ref_cnt);

        orig.p = nullptr;
        orig.ref_cnt = nullptr;
    }

    // 移动赋值
    SharedPtr &operator=(SharedPtr &&rhs) noexcept
    {
        if (this == &rhs)
        {
            return *this;
        }
        if (--(*ref_cnt) == 0)
        {
            delete p;
            delete ref_cnt;
        }
        p = move(rhs.p);
        ref_cnt = move(rhs.ref_cnt);

        rhs.p = nullptr;
        rhs.ref_cnt = nullptr;

        return *this;
    }

    // 析构
    ~SharedPtr()
    {
        --(*ref_cnt);
        if (ref_cnt && *ref_cnt == 0)
        {
            delete p;
            delete ref_cnt;
        }
    }

    // 重载* ->
    T &operator*() { return *p; }

    T *operator->() { return p; }

    // 支持use_count
    size_t use_count() const { return *ref_cnt; }

private:
    T *p;
    size_t *ref_cnt;
};

template <typename T>
class UniquePtr
{
public:
    explicit UniquePtr(T *p = nullptr) : p(p) {}

    // 禁止拷贝构造
    UniquePtr(const UniquePtr &orig) = delete;

    // 禁止拷贝赋值
    UniquePtr &operator=(const UniquePtr &) = delete;

    // 移动构造
    UniquePtr(UniquePtr &&orig) noexcept
    {
        p = move(orig.p);
        orig.p = nullptr;
    }

    // 移动赋值
    UniquePtr &operator=(UniquePtr &&rhs) noexcept
    {
        if (rhis == &rhs)
        {
            return *this;
        }
        delete p;
        p = move(rhs.p);
        rhs.p = nullptr;
        return *this;
    }

    // 析构
    ~UniquePtr()
    {
        delete p;
    }

    // 运算符
    T &operator*() const { return *p; }
    T *operator->() const { return p; }

    // reset
    void reset(T *newp = nullptr)
    {
        delete p;
        p = newp;
    }

private:
    T *p;
};