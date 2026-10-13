/*
 *练习 16.16：把 StrVec 重写为模板 Vec
 原 StrVec 管理vector<string>，改成模板Vec<T>，分配、构造、销毁任意类型 T。
 核心：allocator<T>，elements、first_free、cap三个指针，reserve、resize、push_back。
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
class Vec
{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec();
    void push_back(const T &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:
    T *elements;
    T *first_free;
    T *cap;

    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();

    static allocator<T> alloc;
};
template <typename T>
allocator<T> Vec<T>::alloc;