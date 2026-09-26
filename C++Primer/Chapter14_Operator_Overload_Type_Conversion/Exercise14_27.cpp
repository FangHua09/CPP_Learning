/*
 *知识点：++ -- 前置 / 后置；迭代器指针算术；const 成员函数语义
 规则：
 前置 ++/--：无参数，返回*this引用，成员函数，修改对象。
 后置 ++/--：int 哑元参数，返回原值副本，不返回引用。
 迭代器加法 iter + n、减法 iter - n：非成员，返回新 StrBlobPtr；iter1 - iter2 返回两个迭代器的下标差。
 ++、-- 会修改迭代器本身，不能是 const 成员函数。
 练习 14.27：StrBlobPtr 添加递增、递减运算符
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
    // 前置 ++
    StrBlobPtr &operator++();
    // 后置 ++
    StrBlobPtr operator++(int);
    // 前置 --
    StrBlobPtr &operator--();
    // 后置 --
    StrBlobPtr operator--(int);

    // ...原有其他成员
private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const; // 检查给定下标有没有超过范围
};
// 前置++
StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "越界");
    ++curr;
    return *this;
}
// 后置++
StrBlobPtr StrBlobPtr::operator++(int)
{
    // 后置无需检查 交给前置
    auto ret = *this;
    ++*this;
    return ret;
}
// 前置--
StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "下溢");
    return *this;
}
// 后置--
StrBlobPtr StrBlobPtr::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}