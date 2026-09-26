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

class StrVec
{
public:
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);

    // ========================================

    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    static allocator<string> alloc;
    string *elements, *first_free, *cap;
    void chk_n_alloc();
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void reallocate();
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
};

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    auto lhsbeg = lhs.elements;
    auto rhsbeg = rhs.elements;
    while (lhsbeg && rhsbeg && lhsbeg != lhs.first_free && rhsbeg != rhs.first_free)
    {
        if (*lhsbeg != *rhsbeg)
            return false;
        ++lhsbeg;
        ++rhsbeg;
    }
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    size_t minSz = min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSz; ++i)
    {
        if (lhs.elements[i] < rhs.elements[i])
        {
            return true;
        }
        if (lhs.elements[i] > rhs.elements[i])
        {
            return false;
        }
    }
    // 前面元素全部相等，长度小的更小
    return lhs.size() < rhs.size();
}
bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    return rhs < lhs;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    return !(rhs < lhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs < rhs);
}