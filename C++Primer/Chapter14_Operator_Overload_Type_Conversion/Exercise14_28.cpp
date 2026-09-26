/*
 *练习 14.28：指针算术：+、-
 语义：iter + n：迭代器向后移动 n 个位置；iter - n向前移动 n；iter1 - iter2求下标差值。
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

class StrBlobPtr
{
    friend StrBlobPtr operator+(const StrBlobPtr &lhs, size_t n);
    friend StrBlobPtr operator-(const StrBlobPtr &lhs, size_t n);
    friend ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
    // ...原有代码
    string &operator[](size_t offset);
    const string &operator[](size_t offset) const;

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
};

string &StrBlobPtr::operator[](size_t offset)
{
    auto p = check(curr + offset, "越界");
    return (*p)[curr + offset];
}

const string &StrBlobPtr::operator[](size_t offset) const
{
    auto p = check(curr + offset, "越界");
    return (*p)[curr + offset];
}

StrBlobPtr operator+(const StrBlobPtr &lhs, size_t n)
{
    auto temp = lhs;
    temp.check(temp.curr + n, "越界"); // 先check再加
    temp.curr += n;
    return temp;
}
StrBlobPtr operator-(const StrBlobPtr &lhs, size_t n)
{
    auto temp = lhs;
    temp.curr -= n; // 先减再check
    temp.check(temp.curr - n, "越界");
    return temp;
}
ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (!l || !r || l != r)
        throw runtime_error("iterators point to different containers");
    return r.get() - l.get();
}