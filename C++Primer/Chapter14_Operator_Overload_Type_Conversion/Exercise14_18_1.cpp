/*
 *知识点：关系运算符 < <= > >=规范要点：
 优先实现 <，其余关系运算符基于 < 实现，减少重复代码。
 参数都为 const 引用，不修改对象。
 容器类比较规则：字典序（lexicographical order），和标准库vector、string保持一致。
 字典序规则：依次比较元素，遇到第一个不相等元素决定大小；如果前面全部相等，短的更小。
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
public:
    // 友元声明放在StrBlob类内部
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

    // ===============================

    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    // ================================

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return (lhs.data == rhs.data);
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(rhs < lhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}