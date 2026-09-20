/*
定义一个变量，通过对 11.2 节中的 bookstore（multiset<Sales_data>, 比较器函数指针>）
调用 begin () 初始化这个变量，不使用 auto/decltype。
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
using namespace std;

bool compareIsbn(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

struct Sales_data
{
    string isbn;
};

int main(int argc, char const *argv[])
{
    // 使用decltype推断
    // multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    // 使用函数指针
    multiset<Sales_data, bool (*)(const string &, const string &)> bookstore(compareIsbn);

    multiset<Sales_data, bool (*)(const string &, const string &)>::iterator it = bookstore.begin();

    return 0;
}
