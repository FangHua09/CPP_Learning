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
    // ...原有代码
    string &operator[](size_t i);
    const string &operator[](size_t i) const;

    size_t size() const { return first_free - elements; }

private:
    string *elements, *first_free, *cap;
};

string &StrVec::operator[](size_t i)
{
    if (i >= size())
        throw runtime_error("StrVec下标越界");
    return elements[i];
}

const string &StrVec::operator[](size_t i) const
{
    if (i >= size())
        throw runtime_error("const StrVec下标越界");
    return elements[i];
}
