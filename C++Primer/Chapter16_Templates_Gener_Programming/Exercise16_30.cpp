/*
 * 测试主函数
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
class Blob
{
public:
    using size_type = size_t;
    Blob() : data(SharedPtr<vector<T>>(new vector<T>)) {}
    template <typename Iter>
    Blob(Iter beg, Iter end) : data(SharedPtr<vector<T>>(new vector<T>(beg, end))) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &val) { data->push_back(val); }
    void pop_back() { data->pop_back(); }
    T &back() { return data->back(); }
    T &operator[](size_t idx) { return (*data)[idx]; }

private:
    SharedPtr<vector<T>> data; // 替换为手写SharedPtr
};

int main()
{
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2 = sp1;
    cout << sp1.use_count() << endl; // 输出2

    Blob<string> b;
    b.push_back("Hello");
    b.push_back("C++ Primer");
    cout << b[0] << endl;
    cout << b[1] << '\n';
    return 0;
}
