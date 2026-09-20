// 修改 Person 类，隐藏实现细节，数据成员 private。

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
