// **题目描述**：给 Person 增加返回姓名、住址的成员函数；判断是否应当为 const，解释原因。
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

class Person
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