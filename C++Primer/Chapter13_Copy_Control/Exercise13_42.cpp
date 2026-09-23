/*
题目描述：用 StrVec 代替vector<string>改写 TextQuery / QueryResult。
知识点：只需要把代码中所有vector<string>替换成StrVec，迭代器、begin/end、size 用法和 vector 保持一致。
修改点：
TextQuery 的StrVec file;替代vector<string>保存每行文本；
QueryResult 内保存shared_ptr<StrVec>；
其余逻辑完全不变，因为 StrVec 实现了begin, end, size。
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

// 类vector内部内存分配策略的实现
class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    // 拷贝构造
    StrVec(const StrVec &orig);

    // 析构
    ~StrVec();

    // 拷贝赋值
    StrVec &operator=(const StrVec &rhs);

    // 新增初始值列表构造函数
    StrVec(initializer_list<string> il);

    // push_back
    void push_back(const string &);

    // begin
    string *begin() const { return elements; }

    // end
    string *end() const { return first_free; }

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    // reserve
    void reserve(size_t n);

    // resize
    void resize(size_t n);

private:
    static allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;

    // 四个工具函数
    // 销毁元素 释放内存
    void free();

    // 获取更多内存并拷贝已有元素
    void reallocate();

    // 将元素范围拷贝到新空间返回pair
    pair<string *, string *> alloc_n_copy(const string *, const string *);

    // 至少能存放一个元素的空间，大于一就新空间翻倍
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
};

// 静态成员类外定义
allocator<string> StrVec::alloc; // 需要加到类外面

// resize
void StrVec::resize(size_t n)
{
    if (n > capacity())
    {
        reserve(n);
        // first_free-cap的空间全部构造空串
        for (auto beg = first_free; beg != elements + n; beg++)
        {
            alloc.construct(beg, string());
        }
    }
    else if (n > size())
    {
        // 那就在first_free-n这个区间构造空串
        for (auto beg = first_free; beg != elements + n; beg++)
        {
            alloc.construct(beg, string());
        }
    }
    else if (n < size())
    {
        // 销毁n - first_free的元素
        for (auto end = first_free; end != elements + n;)
        {
            alloc.destroy(--end);
        }
        // 不要 deallocate！内存保留，capacity不变
    }
    // 更新指针
    first_free = elements + n;
}

// reserve：预分配至少new_cap容量
void StrVec::reserve(size_t n)
{
    if (n > capacity())
    {
        // auto newpair = alloc_n_copy(elements, first_free); 这里不复用 实现完整逻辑
        auto beg = alloc.allocate(n); // 新开辟大小为n的空间
        auto dest = beg;              // 新内存起始
        auto elem = elements;         // 旧内存起始
        for (; elem != first_free;)
        {
            alloc.construct(dest++, move(*elem++));
        }
        free();
        elements = beg;
        first_free = dest;
        cap = elements + n;
    }
}

// 销毁元素 释放内存
void StrVec::free()
{
    if (elements)
    {
        // 从尾删到头
        //
        for (auto end = first_free; end != elements;)
        {
            alloc.destroy(--end);
        }
        // 归还空间
        //`deallocate` 的第二个参数，**必须和 allocate 时传入的字节数（元素个数）一致**。
        alloc.deallocate(elements, cap - elements);
    }
}

// 获取更多内存并移动已有元素
void StrVec::reallocate()
{
    auto newcapacity = (capacity()) ? capacity() * 2 : 1;
    auto newp = alloc.allocate(newcapacity);
    auto dest = newp;
    auto elem = elements;
    for (; elem != first_free;)
    {
        alloc.construct(dest++, move(*elem++));
    }
    // 更新
    elements = newp;
    first_free = dest;
    cap = elements + newcapacity;
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto newp = alloc.allocate(e - b);
    return {newp, uninitialized_copy(b, e, newp)};
}

// 拷贝构造
StrVec::StrVec(const StrVec &orig)
{
    auto newpair = alloc_n_copy(orig.elements, orig.first_free); // 返回的是新空间的orgi的值
    elements = newpair.first;
    first_free = cap = newpair.second;
}

// 析构
StrVec::~StrVec()
{
    free();
}

// 拷贝赋值
StrVec &StrVec::operator=(const StrVec &rhs)
{
    // 先拷贝 避免自赋值
    auto newpair = alloc_n_copy(rhs.begin(), rhs.end());
    // 删除左侧对象的空间
    free();
    // 重新赋值
    elements = newpair.first;
    first_free = cap = newpair.second;
    // 返回对象
    return *this;
}

// initialized初始值列表构造函数
StrVec::StrVec(initializer_list<string> il)
{
    auto capacity = il.size();
    auto beg = alloc.allocate(capacity);
    elements = beg;
    for (auto &&s : il)
    {
        alloc.construct(beg++, s);
    }
    first_free = beg;
    cap = elements + capacity;
}

// push_back
void StrVec::push_back(const string &s)
{
    // 先检查是否至少能容纳一个元素
    check_n_alloc();
    alloc.construct(first_free++, s);
}

// ---------------------------------------------
class QueryResult;
class TextQuery
{
public:
    using line_no = size_t;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;

private:
    // 定义一个共享指针指向保存string单词的vec容器
    shared_ptr<StrVec> file;
    // 定义一个map从单词到 行号set的共享指针 的映射
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
public:
    using line_no = size_t;
    friend ostream &print(ostream &os, const QueryResult &);
    QueryResult(const string &sought, shared_ptr<set<line_no>> lines, shared_ptr<StrVec> file) : sought(sought), lines(lines), file(file) {}

private:
    string sought;
    shared_ptr<set<line_no>> lines; // 出现的行号的set的指针
    shared_ptr<StrVec> file;
};
// 类外定义返回结果
QueryResult TextQuery::query(const string &sought) const
{
    // 如果没有找到sought, 返回一个值初始化的静态空lines指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>());
    auto loc = wm.find(sought); // 返回的是一个智能指针指向这个词对应的lines
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // 如果找不到
    return QueryResult(sought, loc->second, file);
}

// 类外定义TextQuery的构造函数
TextQuery::TextQuery(ifstream &ifs) : file(make_shared<StrVec>()) // 先给空智能指针初始化才能->
{
    string line;
    while (getline(ifs, line))
    {
        // 保存每行的line到vec中
        file->push_back(line);
        // 记录行号
        line_no n = file->size() - 1; // 让行号从零开始
        stringstream ss(line);        // 将line变成字节流
        string word;                  // 切割保存每个单词
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
string make_plural(size_t size, const string &prefix, const string &suffix)
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
        // 打印出现行号, 以及对应行号的全行文本
        os << "\t(line: " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
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

// main入口
int main()
{
    ifstream in(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter12_Dynamic_Memory\Exercise12_27.txt)");
    if (!in)
    {
        cerr << "Cannot open text.txt\n";
        return -1;
    }
    runQueries(in);
    return 0;
}