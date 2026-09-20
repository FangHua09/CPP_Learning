/*
题目：给 struct X 添加拷贝赋值运算符和析构函数，写程序测试。
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

struct X
{
    X() { cout << "X()" << '\n'; }
    X(const X &X) { cout << "X(const X&)" << '\n'; }

    X &operator=(const X &)
    {
        cout << "operator=(const X&)" << '\n';
        return *this;
    }
    ~X() { cout << "~X()" << '\n'; }
};

int main(int argc, char const *argv[])
{

    /*
    X obj1;
    X obj2 = obj1;

    ===========

    X()
    X(const X&)
    ~X()
    ~X()
    */

    /*
    X obj1;
    X obj2;
    obj1 = obj2;

    =================

    X()
    X()
    operator=(const X &)
    ~X()
    ~X()
    */
 


    /*
    vector<X>xvec;
    xvec.push_back(X());
    ===============
    X()
    X(const X&)
    ~X()
    ~X()
    */

    /*
    X* px = new X();
    delete px;

    ==========

    X()
    ~X()
    */

    return 0;
}
