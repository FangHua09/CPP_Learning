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
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);

    String();
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();
    size_t size() const { return end - elements; }

private:
    char *elements;
    char *end;
    static allocator<char> alloc;
    void free();
    pair<char *, char *> alloc_n_copy(const char *, const char *);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
};

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    auto lhsbeg = lhs.elements;
    auto rhsbeg = rhs.elements;
    while (lhsbeg && rhsbeg && lhsbeg != lhs.end && rhsbeg != rhs.end)
    {
        if (*lhsbeg != *rhsbeg)
            return false;
        ++lhsbeg;
        ++rhsbeg;
    }
    return true;
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    size_t minsz = min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minsz; i++)
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
    return lhs.size() < rhs.size();
}
bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}