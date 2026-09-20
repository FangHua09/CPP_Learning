/*
题目描述
重写 TextQuery 和 QueryResult 类，用 StrBlob 代替 vector<string> 保存输入文件。
知识点
StrBlob：用 shared_ptr 管理 vector<string>的自定义类，之前章节写过；用 StrBlob 替代裸 shared_ptr<vector<string>>，封装底层 vector 操作。
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
    bool empty() const { return data->empty(); }
    size_type size() const { return data->size(); } // 添加了常量成员函数的限定 使得conststrBlob对象也可以调用这些函数。this隐式添加了底层const指针，所以可以支持重载，但没必要
    // this 都是顶层的 const 。只是 const 成员函数又多了一层底层 const 限定，重载只看底层 const 不看顶层 const

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
    StrBlobPtr cbegin() const;
    StrBlobPtr cend() const;
    /*
    strBlob 类内只写函数声明，把 begin ()、end () 的函数实现移到 StrBlobPtr 类定义完成之后。
    */

private:
    shared_ptr<vector<string>> data;
    // 辅助检查下标工具函数
    void check(size_type i, const string &msg) const;
};

// 类外定义构造函数
strBlob::strBlob() : data(make_shared<vector<string>>()) {}
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
    // 两参数构造（这里是无const strBlob版本
    StrBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    // 新增一个const版本
    StrBlobPtr(const strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

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
StrBlobPtr strBlob::end() { return StrBlobPtr(*this, data->size()); }
StrBlobPtr strBlob::begin() { return StrBlobPtr(*this, 0); }

StrBlobPtr strBlob::cbegin() const { return StrBlobPtr(*this, 0); }
StrBlobPtr strBlob::cend() const { return StrBlobPtr(*this, data->size()); }

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

// ========================

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;

private:
    // 定义一个共享指针指向保存string单词的vec容器
    strBlob file; // 替换 shared_ptr<vector<string>>，改用StrBlob

    // 定义一个map从单词到 行号set的共享指针 的映射
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
public:
    using line_no = vector<string>::size_type;
    friend ostream &print(ostream &os, const QueryResult &);
    QueryResult(const string &sought, shared_ptr<set<line_no>> lines, const strBlob& file) : sought(sought), lines(lines), file(file) {}

private:
    string sought;
    shared_ptr<set<line_no>> lines; // 出现的行号的set的指针
    strBlob file;                   // 替换 shared_ptr<vector<string>>，改用StrBlob
};
// 类外定义返回结果
QueryResult TextQuery::query(const string &sought) const
{
    // 如果没有找到sought, 返回一个值初始化的静态空lines指针。只初始化一次
    static shared_ptr<set<line_no>> nodata(new set<line_no>());
    auto loc = wm.find(sought); // 返回的是一个智能指针指向这个词对应的lines
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // 如果找不到
    return QueryResult(sought, loc->second, file);
}

// 类外定义TextQuery的构造函数
TextQuery::TextQuery(ifstream &ifs)
{
    string line;
    while (getline(ifs, line))
    {
        // 保存每行的line到vec中
        file.push_back(line); // 这里的pushback是包装后的pushback
        // 记录行号
        line_no n = file.size() - 1; // 让行号从零开始 （这里的size（）同样是包装后的size
        stringstream ss(line);       // 将line变成字节流
        string word;                 // 切割保存每个单词
        while (ss >> word)
        {
            auto &p = wm[word]; // std::shared_ptr<std::set<TextQuery::line_no>> &p
            // 如果为word第一次出现 返回的就是空指针
            if (!p)
            {
                p = make_shared<set<line_no>>(); // 先分配一片空的set动态内存交给shareptr管理
            }
            p->insert(n); // 在这片set内存中存入当前word出现的行号 如果存在则什么都不做。自动升序
        }
    }
}

// 工具函数
string make_plural(vector<string>::size_type size, const string &prefix, const string &suffix)
{
    return ((size > 1) ? prefix + suffix : prefix);
}

// 类外定义打印函数
ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs: " << qr.lines->size() << make_plural(qr.lines->size(), "time", "s") << endl;
    // 打印单词的每一行
    for (auto &&num : *qr.lines) // 遍历lines中的每个行号nun
    {
        // 构造StrBlobPtr，直接指定curr=num，定位到对应行
        StrBlobPtr p(qr.file, num); // 这里报错因为StrBlobPtr原始构造的第一个参数是strBlob&的无const版本，这里普通引用试图绑定常量对象
        os << "\t(line: " << num + 1 << ") " << p.deref() << endl;
    }
    return os;
}

// 使用这个类的函数
void runQueries(ifstream &ifs)
{
    // TextQuery保存文件并且建立查询map
    TextQuery tq(ifs);
    // 与用户交互 不断输入
    while (true)
    {
        cout << "enter a word to look for, or 'q' to quit" << '\n';
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

// main测试入口
int main()
{
    ifstream in(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter12_Dynamic_Memory\Exercise12_27.txtc)");
    if (!in)
    {
        cerr << "can not open file" << endl;
        return 1;
    }
    runQueries(in);
    return 0;
}