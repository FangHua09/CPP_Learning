/*
 *知识点：解引用 *、箭头 -> 运算符重载规则：
 operator*：返回元素引用；operator-> 返回指针（智能指针风格）。二者都是成员函数。
 -> 特殊：编译器会递归调用 ->，直到拿到原生指针。
 迭代器类一般成对提供普通版本与 const 版本。
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
public:
    string &operator*() const;
    string *operator->() const;

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
};
string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "越界");
    return (*p)[curr];
}
string *StrBlobPtr::operator->() const
{
    return &(this->operator*());
}

// ConstStrBlobPtr（const 迭代器，返回 const 引用）

class ConstStrBlobPtr
{
public:
    const string &operator*() const;
    const string *operator->() const;

private:
    weak_ptr<const vector<string>> wptr;
    size_t curr;
    shared_ptr<const vector<string>> check(size_t i, const string &msg) const;
};

const string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "越界");
    return (*p)[curr];
}
const string *ConstStrBlobPtr::operator->() const
{
    return &(this->operator*());
}
/*
说明：ConstStrBlobPtr 底层指向const vector<string>，所以解引用得到const string&，箭头返回const string*，不能修改元素。
*/