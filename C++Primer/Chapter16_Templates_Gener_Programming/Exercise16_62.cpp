/*
 *练习 16.62：自定义 hash<Sales_data>，unordered_multiset<Sales_data>
 要求：自定义 hash 模板特例化；unordered_multiset 存储 Sales_data，同时需要两个东西
 hash<Sales_data> 哈希函数（计算哈希值）
 == 相等运算符（unordered 容器判断碰撞相等）
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
#include <unordered_set>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

// 特例化 std::hash
// 即提供一个Sales_data类型的特例化版本
namespace std
{
    template <>
    struct hash<Sales_data>
    {

        friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const
        {
            return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
        }
    };
}

int main(int argc, char const *argv[])
{
    unordered_set<Sales_data> records;
    records.insert({"001", 10, 200});
    records.insert({"002", 5, 100});
    records.insert({"001", 10, 200});

    for (auto &item : records)
    {
        cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
    }
    return 0;
}


// using namespace std;

// template <typename T>
// int compare(const T &t1, const T &t2)
// {
//     if (t1 < t2)
//         return -1;
//     if (t1 > t2)
//         return 1;
//     return 0;
// }

// // 模板全特化
// template <>
// int compare(const char *const &s1, const char *const &s2)
// {
//     return strcmp(s1, s2);
// }

/*
类模板：可以全特化，也可以【部分特化】（重点！）
函数不能部分特化，但类模板可以部分特化。
部分特化：只固定一部分模板参数，剩下模板参数依然保留。
*/

/*
unordered_map / unordered_set 默认只给内置类型提供 hash。
如果你想放自定义类Sales_data，标准库没有 hash 函数，编译报错。
解决办法：对 std::hash 做类模板全特化。
*/