/*
 *练习 14.23：StrVec 增加 initializer_list<string> 赋值运算符

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

class StrVec
{
public:
    StrVec &operator=(initializer_list<string> il);
    // ...其余原有成员
private:
    static allocator<string> alloc;
    string *elements, *first_free, *cap;
    void free();
    pair<string *, string *> alloc_n_copy(const string *, const string *);
};

StrVec &StrVec::operator=(initializer_list<string> il)
{
    auto newpair = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newpair.first;
    first_free = newpair.second;
    cap = newpair.second;
    return *this;
}