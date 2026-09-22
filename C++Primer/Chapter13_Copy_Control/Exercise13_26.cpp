/*
编写值版本 StrBlob（沿用之前 StrBlob 框架）
*/
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    //拷贝构造函数
    StrBlob(const StrBlob& orgi): data(make_shared<vector<string>>(orgi.data)){}

    // 拷贝赋值
    StrBlob& operator= (const StrBlob& rhs){
        // 先创建指向*rhs.data的临时对象，内容是一样的 但是是副本新空间
        auto newp = make_shared<vector<string>>(*rhs.data);
        // 
        this->data = newp;
        return *this;
    }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }
    void pop_back() { data->pop_back(); }
    string &front() { return data->front(); }
    string &back() { return data->back(); }

private:
    shared_ptr<vector<string>> data;
};
