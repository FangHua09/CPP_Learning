/*
 *练习 16.61：自己实现 make_shared
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

template <typename T>
class my_make_shared
{
    my_make_shared() : p(nullptr);

    template <typename... Args>
    my_make_shared(const Args &...agrs)
    {
        p = shared_ptr<T>(new T(forward<Args>(args)...));  // 对于sharedptr来说需要用指向对象的裸指针来初始化
        return p;
    }

    ~my_make_shared() = default;

private:
    T *p;
};