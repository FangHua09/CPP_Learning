/*
编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。
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

    const string &front() const;
    const string &back() const;

    // begin，end函数
    // StrBlobPtr begin() { return StrBlobPtr(*this, 0); }
    // StrBlobPtr end() { return StrBlobPtr(*this, data->size()); }
    StrBlobPtr begin();
    StrBlobPtr end();
    /*
    strBlob 类内只写函数声明，把 begin ()、end () 的函数实现移到 StrBlobPtr 类定义完成之后。
    */

private:
    shared_ptr<vector<string>> data;
    // 辅助检查下标工具函数
    void check(size_type i, const string &msg) const;
};

// 类外定义构造函数
strBlob::strBlob(): data(make_shared<vector<string>>()){}
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

// 类外定义返回头尾的元素访问(额外重载cosnt版本, 常函数必须返回const引用)

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

const string &strBlob::front() const
{
    check(0, "front on empty strBlob");
    return data->front();
}
const string &strBlob::back() const
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
    const string &deref() const;
    // 前缀递增
    StrBlobPtr &incr();

    // 获取下标函数
    const size_t getter_curr() const { return curr; }

private:
    // check函数 检查越界，正常则返回wptr对应的share_ptr
    shared_ptr<vector<string>> check(size_t sz, const string &msg) const;
    // 保存一个weak指针，表示底层指向的vector<string> 可能被销毁
    weak_ptr<vector<string>> wptr;
    // 保存当前下标
    size_t curr;
};

// 补充定义strBlob的begin，end函数
StrBlobPtr strBlob::end(){return StrBlobPtr(*this, data->size());}
StrBlobPtr strBlob::begin(){return StrBlobPtr(*this, 0);}

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
const string &StrBlobPtr::deref() const
{
    auto p = check(curr, "取引用越界访问");
    return (*p)[curr];
}

// 类外定义前缀递增
StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "前缀递增访问越界");
    ++curr;
    return *this; // 传递递增后对象引用
}

int main(int argc, char const *argv[])
{
    ifstream ifs(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter12_Dynamic_Memory\Exercise12_20.txt)");
    if (!ifs)
    {
        cerr << "cannot open file" << endl;
        return -1;
    }

    strBlob sb;
    string s;
    while (getline(ifs, s))
    {
        sb.push_back(s);
    }

    for (auto p = sb.begin(); (p.getter_curr() != (sb.end()).getter_curr()); p.incr())
    {
        cout << p.deref() << '\n';
    }

    return 0;
}
/*
How are you?
I am fine
thank you
*/