/*
 *练习 16.13：BlobPtr 相等 / 关系运算符，选择何种友元
 两种方案：
 把运算符定义为普通非成员函数，把 BlobPtr<T>的运算符声明为友元；
 推荐：相等运算符== !=作为模板友元，同一模板实例的 BlobPtr 才可以互相比较。
 理由：
 比较两个BlobPtr<T>，需要访问 BlobPtr 的私有成员wptr、curr。
 把operator==声明为模板友元，只允许相同类型参数的 BlobPtr 互相比较，避免不同实例之间错误比较。
 
 template<typename T>
 class BlobPtr {
     template<typename U>
     friend bool operator==(const BlobPtr<U>&, const BlobPtr<U>&);
     template<typename U>
     friend bool operator!=(const BlobPtr<U>&, const BlobPtr<U>&);
 private:
     std::weak_ptr<std::vector<T>> wptr;
     std::size_t curr;
 };
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
class Blob;
template <typename T>
class BlobPtr;
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T>
class Blob
{
    // 1： 一对一关系 每个Blob实例都可以将访问权限授予相同类型实例化的BlobPtr和相等运算符
    friend bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);
    friend class BlobPtr<T>;
};
/*
Blob<int> 与BlobPtr<int>和operator==(const Blob<int> &lhs, const Blob<int> &rhs);
是友元
*/

// 一个类也可以将另外一个模板的每个实例都声明成自己的友元，或者部分实例
template <typename T>
class Pal; // 将模板特定实例声明成友元会用到前置声明
class C
{
    friend class Pal<C>; // 2： 普通类C指定特定实例作为友元

    template <typename T>
    friend class Pal2; //  3： Pal2所有实例都是C的友元 这种情况不必声明友元
};

class Pal3;
template <typename T>
class C2
{
    friend class Pal<T>; // 4： C2的每个实例将相同实例化的Pal声明成友元

    // Pal2 的每个实例都是C2的友元 不需要前置声明 模板名不一样
    template <typename X> friend class Pal2;

    // Pal3是非模板普通类， 它是C2所有实例的友元
    friend class Pal3;
};
