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

class StrBlob
{
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return (lhs.data == rhs.data);
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

class StrBlobPtr
{
public:
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr();

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto lhsPtr = lhs.wptr.lock();
    auto rhsPtr = rhs.wptr.lock();
    if (lhsPtr && rhsPtr)
    {
        return lhs == rhs && lhs.curr == rhs.curr;
    }
    else
        return false;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto lhsbeg = lhs.wptr.lock();
    auto rhsbeg = rhs.wptr.lock();
    while (lhsbeg && rhsbeg && lhsbeg == rhsbeg)
    {
        return lhs.curr < rhs.curr;
    }
    return false;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    
    return rhs < lhs;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(rhs > lhs);
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}