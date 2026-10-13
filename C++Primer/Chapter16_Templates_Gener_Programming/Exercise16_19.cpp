/*
 *练习 16.19：函数接收容器引用，用size_type+size () 打印元素
 要求：使用容器的size_type类型，size()成员循环
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
    using size_type = typename Container::size_type;
    for (size_type i = 0; i < c.size(); i++)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    list<string> lst{"hi", "cpp"};
    print(v);
    // print(lst); // list不支持下标[]，会编译报错！
    return 0;
}