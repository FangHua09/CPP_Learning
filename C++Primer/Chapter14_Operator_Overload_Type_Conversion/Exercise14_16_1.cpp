/*
 *知识点：相等运算符规范规则：
 == 判断对象内容相等，非成员函数，两个参数都是const引用。
 != 直接用 !(lhs == rhs) 实现，不要重复写比较逻辑。
 相等运算符不应该修改对象，参数必须加const。
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
public:
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
bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    return !(lhs == rhs);
}