/*
 *背景：文本查询 Query 系统，表达式：Query("fiery") & Query("bird") | Query("wind")
 练习 15.39：实现 Query 与 Query_base，求值并打印结果
 完整实现（包含eval，可以运行求值，打印构造 /rep 信息）
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
class QueryResult
{
public:
    using line_no = vector<string>::size_type;
    QueryResult(const string &sought, shared_ptr<vector<string>> file, shared_ptr<set<line_no>> lines) : sought(sought), file(file), lines(lines) {}
    friend ostream &print(ostream &os, const QueryResult &);
    // 返回begin，end迭代器
    set<line_no>::iterator begin() { return lines->begin(); }
    set<line_no>::iterator end() { return lines->end(); }
    // 返回get_file返回指向带查询文件的共享指针
    shared_ptr<vector<string>> get_file() { return file; }

private:
    string sought;
    // 定义一个指向保存 string 单词的 vec 容器的智能指针
    shared_ptr<vector<string>> file;
    // 定义一个指向行号 set 的智能指针
    shared_ptr<set<line_no>> lines;
};
ostream &print(ostream &os, const QueryResult &queryresult)
{
    os << queryresult.sought << "出现了：" << queryresult.lines->size() << "次" << endl;
    // 打印单词的每一行
    for (auto &&line : *(queryresult.lines))
    {
        os << "line" << line + 1 << ":" << (*queryresult.file)[line] << endl;
    }
    return os;
}
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &ifs);
    QueryResult query(const string &s) const;

private:
    // 定义一个共享指针指向保存 string 单词的 vec 容器
    shared_ptr<vector<string>> file;
    // 定义一个 map 从单词到 行号 set 的共享指针 的映射
    map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &ifs) : file(make_shared<vector<string>>())
{
    string line;
    while (getline(ifs, line))
    {
        // line_no no = file->size () - 1; 先插入再获取
        file->push_back(line);
        line_no no = file->size() - 1;
        string word;
        stringstream ss(line);
        while (ss >> word)
        {
            auto &sp = wm[word];
            if (!sp)
            {
                // 如果该单词在 map 中没有对应 就给它分配一个新的行号 set 的指针
                sp = make_shared<set<line_no>>();
            }
            sp->insert(no);
        }
    }
}
QueryResult TextQuery::query(const string &sought) const
{
    /*
    返回格式
    string sought;
    // 定义一个指向保存 string 单词的 vec 容器的智能指针
    shared_ptr<vector<string>> file;
    // 定义一个指向行号 set 的智能指针
    shared_ptr<set<line_no>> lines; //依靠行号来定位文本的 所以没有查到就返回指向空行号 set 的指针
    */
    static auto no_data = shared_ptr<set<line_no>>(new set<line_no>());
    auto sp = wm.find(sought);
    if (sp == wm.end())
        return QueryResult(sought, file, no_data);
    else
        return QueryResult(sought, file, sp->second);
}
// 使用这个类的函数
void runQueries(ifstream &ifs)
{
    // TextQuery 保存文件并且建立查询 map
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
class Query_base;
class Query
{
    // 友元声明
    friend ostream &operator<<(ostream &os, const Query &q);
    friend Query operator&(const Query &lhs, const Query &rhs);
    friend Query operator|(const Query &lhs, const Query &rhs);
    friend Query operator~(const Query &query);

public:
    // 公有的 对外提供操作Query_base继承体系的接口
    Query(const string &s);
    QueryResult eval(const TextQuery &text) const;

    string rep() const;

private:
    // 构造函数
    Query(shared_ptr<Query_base> p) : q(p)
    {
    } // 为什么设置为私有？因为仅供友元运算符函数使用
    shared_ptr<Query_base> q;
};
// 定义Query的输出运算符
ostream &operator<<(ostream &os, const Query &q)
{
    os << q.rep();
    return os;
}
class Query_base
{
    // 友元声明
    friend class Query;

protected:
    // 纯虚函数接口
    virtual QueryResult eval(const TextQuery &text) const = 0;
    virtual string rep() const = 0;
    using line_no = QueryResult::line_no;
    // 虚析构
    virtual ~Query_base() = default;
};

// 放到 Query_base 完整定义之后！！
inline QueryResult Query::eval(const TextQuery &text) const
{
    return q->eval(text);
}
inline string Query::rep() const
{
    return q->rep();
}
class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(string query_word) : sought(query_word)
    {
        cout << "构造 WordQuery: " << query_word << endl;
    }
    // 覆盖纯虚函数
    QueryResult eval(const TextQuery &text) const override
    {
        return text.query(sought);
    }
    string rep() const override
    {
        return sought;
    }
    string sought;
};

Query::Query(const string &s) : q(shared_ptr<WordQuery>(new WordQuery(s))) {}
class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(Query query) : query(query)
    {
        cout << "构造 NotQuery" << endl;
    }
    virtual QueryResult eval(const TextQuery &text) const override;
    virtual string rep() const override
    {
        return "~(" + query.rep() + ")";
    }
    Query query;
};
inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}
QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto ret = make_shared<set<line_no>>();
    auto result = query.eval(text);
    auto begin = result.begin();
    auto end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; n++)
    {
        if (begin == end || n != *begin)
        {
            ret->insert(n);
        }
        else if (n == *begin)
        {
            ++begin;
        }
    }
    return QueryResult(rep(), result.get_file(), ret);
}
class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s)
    {
        cout << "构造 BinaryQuery, op=" << s << endl;
    }
    string rep() const override
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    // 此处eval不实现 仍然是抽象基类，仍然是纯虚函数
    QueryResult eval(const TextQuery &text) const override = 0;
    Query lhs, rhs;
    string opSym;
};
class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &lhs, const Query &rhs);
    AndQuery(Query l, Query r) : BinaryQuery(l, r, "&")
    {
        cout << "构造 AndQuery" << endl;
    }
    // 继承直接基类对rep的重写
    QueryResult eval(const TextQuery &text) const override;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
// 覆盖eval函数
QueryResult AndQuery::eval(const TextQuery &text) const
{
    /*
    返回格式
    string sought;
    // 定义一个指向保存 string 单词的 vec 容器的智能指针
    shared_ptr<vector<string>> file;
    // 定义一个指向行号 set 的智能指针
    shared_ptr<set<line_no>> lines; //依靠行号来定位文本的 所以没有查到就返回指向空行号 set 的指针
    */
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret, ret->begin()));
    return QueryResult(rep(), left.get_file(), ret);
}
class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &lhs, const Query &rhs);
    OrQuery(Query l, Query r) : BinaryQuery(l, r, "|")
    {
        cout << "构造 OrQuery" << endl;
    }
    // 继承直接基类对rep的重写
    QueryResult eval(const TextQuery &text) const override;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
// 覆盖eval函数
QueryResult OrQuery::eval(const TextQuery &text) const
{
    /*
    返回格式
    string sought;
    // 定义一个指向保存 string 单词的 vec 容器的智能指针
    shared_ptr<vector<string>> file;
    // 定义一个指向行号 set 的智能指针
    shared_ptr<set<line_no>> lines; //依靠行号来定位文本的 所以没有查到就返回指向空行号 set 的指针
    */
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret = make_shared<set<line_no>>(left.begin(), left.end());
    ret->insert(right.begin(), right.end());
    return QueryResult(rep(), left.get_file(), ret);
}
int main()
{
    ifstream in(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter15_Object_Oriented_Programming\Exercise15_41.txt)");
    if (!in)
    {
        cerr << "Cannot open story.txt\n";
        return 1;
    }
    TextQuery tq(in);
    in.close();

    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << "==== Query expression ====" << endl;
    cout << q << endl;
    cout << "==== Query result ====" << endl;
    QueryResult res = q.eval(tq);
    print(cout, res);

    // cout << "\n==== Interactive runQueries ====\n";
    // ifstream in2("story.txt");
    // runQueries(in2);
    return 0;
}