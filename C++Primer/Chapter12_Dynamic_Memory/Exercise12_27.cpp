/*
TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两个类编写你自己的版本。

**知识点**

1. `shared_ptr` 共享智能指针，多个对象共享堆资源，引用计数自动管理内存释放；
2. `vector<string>` 存储文档每一行原文；`map<string, shared_ptr<set<line_no>>>` 建立单词→行号集合映射；
3. 类的前置声明、友元函数，友元可以访问类私有成员；
4. `static` 局部静态变量：函数第一次调用时初始化，程序全程只创建一次；
5. `istringstream` 字符串流，用来按空格分割一行文本得到单词。
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

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;

private:
    // 定义一个共享指针指向保存string单词的vec容器
    shared_ptr<vector<string>> file;
    // 定义一个map从单词到 行号set的共享指针 的映射
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
public:
    using line_no = vector<string>::size_type;
    friend ostream &print(ostream &os, const QueryResult &);
    QueryResult(const string &sought, shared_ptr<set<line_no>> lines, shared_ptr<vector<string>> file) : sought(sought), lines(lines), file(file) {}

private:
    string sought;
    shared_ptr<set<line_no>> lines; // 出现的行号的set的指针
    shared_ptr<vector<string>> file;
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
TextQuery::TextQuery(ifstream &ifs) : file(make_shared<vector<string>>()) // 先给空智能指针初始化才能->
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
string make_plural(vector<string>::size_type size ,const string& prefix, const string& suffix)
{
    return ((size > 1) ? prefix + suffix: prefix);
}

// 类外定义打印函数
ostream &print(ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs: " << qr.lines->size() << make_plural(qr.lines->size(), "time", "s") << endl;
    // 打印单词的每一行
    for (auto &&num : *qr.lines) //遍历lines中的每个行号nun
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
    if (!in) {
        cerr << "Cannot open text.txt\n";
        return -1;
    }
    runQueries(in);
    return 0;
}