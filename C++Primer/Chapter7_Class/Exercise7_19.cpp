// Person 类哪些成员 public，哪些 private，解释原因。
/*
private：name、address：数据成员。不让外部直接读写，避免外部随意篡改对象数据；只能通过类提供的成员函数访问修改。
public：构造函数、get_name ()、get_addr ()、read ()，是类对外接口。外部代码可以调用这些函数完成对象创建、读取姓名住址、读取输入。
理由：封装。把数据隐藏，只开放受控接口，保证对象数据安全。外部不能直接修改 name/address，只能通过类提供函数操作。
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

//private:
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
