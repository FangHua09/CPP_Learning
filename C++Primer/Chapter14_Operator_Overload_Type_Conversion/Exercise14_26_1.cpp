/*
 *C++ Primer 练习 14.26：StrBlob、StrBlobPtr、StrVec、String 下标运算符
 ✅ 规范要点：
 下标运算符需要两个版本：普通版本（返回引用，可写） + const 版本（返回 const 引用，只读）
 做下标范围检查，越界抛出异常。
 [] 必须是成员函数，不能是普通非成员重载。
 1. StrBlob 的下标运算符
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

class StrBlob
{
public:
    // ...原有代码
    using size_type = vector<string>::size_type;
    string &operator[](const size_type &sz);
    const string &operator[](const size_type &sz) const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

string &StrBlob::operator[](const size_type &sz)
{
    check(sz, "越界");
    return (*data)[sz];
}
const string &StrBlob::operator[](const size_type &sz) const
{
    check(sz, "越界");
    return (*data)[sz];
}