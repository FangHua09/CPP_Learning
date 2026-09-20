/*

*/

/*
题目：编写你自己的 StrBlob 类，包含 const 版本的 front 和 back。
知识点：重载成员函数（const / 非 const 版本）；const成员函数；const对象只能调用 const 成员；const 引用返回禁止修改。
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

// 声明友元之前要前置声明
class StrBlobPtr;
class strBlob
{
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    strBlob();
    strBlob(initializer_list<string> il);

    // 返回空或者数量的元素
    bool empty() { return data->empty(); }
    size_type size() { return data->size(); }

    // 增加或者删除元素
    void push_back(const string &s);
    void pop_back();

    // 返回头尾的元素访问(额外重载cosnt版本)
    string &front();
    string &back();

    string &front() const;
    string &back() const;

    //begin，end函数
    StrBlobPtr begin(){return StrBlobPtr(*this, 0);}
    StrBlobPtr end(){return StrBlobPtr(*this, data->size());}
    
private:
    shared_ptr<vector<string>> data;
    // 辅助检查下标工具函数
    void check(size_type i, const string &msg) const;
};

// 类外定义构造函数
strBlob::strBlob() = default;
strBlob::strBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

// 类外定义工具函数
void strBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

// 类外定义增加或者删除元素
void strBlob::push_back(const string &s)
{
    data->push_back(s);
}
void strBlob::pop_back()
{
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}

// 类外定义返回头尾的元素访问(额外重载cosnt版本)

string &strBlob::front()
{
    check(0, "front on empty strBlob");
    return data->front();
}
string &strBlob::back()
{
    check(0, "back on empty strBlob");
    return data->back();
}

string &strBlob::front() const
{
    check(0, "front on empty strBlob");
    return data->front();
}
string &strBlob::back() const
{
    check(0, "back on empty strBlob");
    return data->back();
}

// 定义一个伴随指针类StrBlobPtr
class StrBlobPtr
{
public:
    // 默认构造函数 显示初始化curr，隐式初始化wptr
    StrBlobPtr() : curr(0) {}
    // 两参数构造
    StrBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    // 取引用运算符函数
    string &deref() const;
    // 前缀递增
    StrBlobPtr &incr();

private:
    // check函数 检查越界，正常则返回wptr对应的share_ptr
    shared_ptr<vector<string>> check(size_t sz, const string &msg) const;
    // 保存一个weak指针，表示底层指向的vector<string> 可能被销毁
    weak_ptr<vector<string>> wptr;
    // 保存当前下标
    size_t curr;
};

// 类外定义工具函数
shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const
{
    auto ret = wptr.lock(); // 如果指向对象为空返回空，否则shared_ptr
    if (!ret)
    {
        throw runtime_error("指向空对象！"); // 抛出空指针异常
    }
    if (sz >= ret->size())
    {
        throw out_of_range(msg); // 抛出越界异常
    }
    return ret;
}

// 类外定义取引用运算符
string & StrBlobPtr::deref() const{
    auto p = check(curr, "取引用越界访问");
    return (*p)[curr];
}

// 类外定义前缀递增
StrBlobPtr & StrBlobPtr::incr(){
    check(curr, "前缀递增访问越界");
    ++curr;
    return *this; // 传递递增后对象引用
}

