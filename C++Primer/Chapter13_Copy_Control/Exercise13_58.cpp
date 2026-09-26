/*
编写 Foo 类，加打印语句验证上面两题
完整可编译代码：
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
    Foo(const vector<int> &v) : data(v) {}
    Foo sorted() const &; // 左值版本的sorted成员函数
    Foo sorted() &&;      // 右值版本的sorted
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "右值版本sorted" << '\n';
    sort(this->data.begin(), this->data.end()); // 可以原址排序
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "左值版本sorted" << '\n';
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret; // 返回副本 不能原址排序
}

int main()
{
    Foo lf({3, 1, 2});
    Foo lres = lf.sorted(); // f是左值，调用sorted() const &
    for (auto &&i : lres.data)
    {
        cout << i << ' ';
    }

    cout << '\n';

    
    Foo rres = Foo ({3, 1, 2}).sorted();
    for (auto &&i : rres.data)
    {
        cout << i << ' ';
    }

    ;
    return 0;
}
/*
左值版本sorted
1 2 3 
右值版本sorted
1 2 3 
*/