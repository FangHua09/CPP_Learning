/*
 *练习 16.20：重写上面函数，用begin() end()迭代器循环
 迭代器版本，支持所有标准容器（vector /list/map 等）
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

template <typename Container>
void print(const Container &c)
{
    // size_type：容器定义的无符号整数类型
    // using size_type = typename Container::size_type;
    for (auto beg = c.begin(); beg != c.end(); ++beg)
    {
        cout << *beg << ' ';
    }
    cout << '\n';
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    list<string> lst{"hello", "template"};
    print(v);
    print(lst);
    return 0;
}