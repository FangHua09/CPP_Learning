// 为 Person 类编写 read、print 操作
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
    string get_name() const
    {
        return name;
    }

    string get_addr() const
    {
        return address;
    }

    std::string name;
    std::string address;
};

// read 
istream& read(istream& is, Person& p) {
    is >> p.name >> p.address;
    return is;
}

// print
ostream& print(ostream& os, const Person &p) {
    os << p.get_name() << " " << p.get_addr();
    return os;
}