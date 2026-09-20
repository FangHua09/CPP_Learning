/*
接收`string`单参数构造函数应该设置`explicit`。原因：字符串代表人名，不等于 Person 对象，不希望编译器悄悄把 string 隐式转为 Person 对象，避免意外隐式转换 bug。
*/
#include <iostream>
#include <vector>
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

using namespace std;

struct Person
{
    //友元声明：
    friend istream &read(istream &is, Person &p);
    
    // 默认构造
    Person() = default;

    // istream构造
    Person(istream &is)
    {
        read(cin, *this);
    }

    // 值构造
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}

    // 单参数构造
    explicit Person(const string& name) : Person(name, "unknow"){}// 仅允许直接初始化Person p("Yang")或者Person p(String("Yang")); 此时name：Yang。Address：unknow。

    string get_name() const
    {
        return name;
    }

    string get_addr() const
    {
        return address;
    }

private:
    std::string name;
    std::string address;
};

// read
istream &read(istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

// print
ostream &print(ostream &os, const Person &p)
{
    os << p.get_name() << " " << p.get_addr();
    return os;
}
