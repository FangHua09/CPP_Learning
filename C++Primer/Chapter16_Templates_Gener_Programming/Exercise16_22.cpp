/*
 *练习 16.22：修改 TextQuery，shared_ptr 使用 DebugDelete 删除器
 原 TextQuery：用shared_ptr<vector<string>>保存文件内容；创建 shared_ptr 的时候，传入DebugDelete()作为删除器。
 关键改动点
 原来创建 shared_ptr：
 // 旧代码
 shared_ptr<vector<string>> file(new vector<string>);
 改成：
 shared_ptr<vector<string>> file(new vector<string>, DebugDelete());
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
    template <typename T>
    void operator()(T *t) const
    {
        os << "DebugDelete: deleting pointer" << endl;
        delete t;
    }

private:
    ostream &os;
};

class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream &in);
    QueryResult query(const string &s) const;

private:
    // shared_ptr，删除器类型是 DebugDelete
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<size_t>>> word_map;
};

TextQuery::TextQuery(ifstream &in)
    // 构造shared_ptr，传入DebugDelete实例
    : file(new vector<string>, DebugDelete())
{
    string line;
    size_t line_no = 0;
    while (getline(in, line))
    {
        file->push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            auto &lines = word_map[word];
            if (!lines)
                lines.reset(new set<size_t>);
            lines->insert(line_no);
        }
        line_no++;
    }
}
