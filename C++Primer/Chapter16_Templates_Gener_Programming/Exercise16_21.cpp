/*
 *练习 16.21：编写 DebugDelete
 DebugDelete 是函数对象类，重载()调用运算符；作为shared_ptr的自定义删除器，释放内存时打印调试信息。
 
 核心知识点：
 operator()写成模板，这样DebugDelete可以删除任意类型指针；
 作为shared_ptr的删除器，类型是 DebugDelete，对象实例传给 shared_ptr 构造；
 析构 shared_ptr 的时候，会自动执行DebugDelete对象(指针)，触发operator()。
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

class DebugDelete
{
public:
    DebugDelete() : os(cerr) {}

    // 重载调用运算符
    template <typename T>
    void operator()(T *t)
    {
        os << "DebugDelete: deleting pointer" << endl;
        delete t;
    }

private:
    ostream &os;
};
