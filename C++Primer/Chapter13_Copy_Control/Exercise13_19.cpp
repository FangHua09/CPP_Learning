/*
题目：Employee 类需要自己定义拷贝控制成员吗？为什么？如果需要实现。✅ 不需要自定义拷贝构造、拷贝赋值、析构。理由：
类的成员只有string name（类类型，自带拷贝控制）和内置int id；
合成拷贝控制会逐成员拷贝；
业务要求：雇员编号 id 是唯一标识，不能复制！
⚠️ 关键点：如果允许拷贝，新对象会拷贝旧对象的 id，出现两个雇员同一个编号，这不符合业务语义。👉 所以必须禁止拷贝！实现：把拷贝构造、拷贝赋值声明为 private（C++11 后可以用delete删除）
*/
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    // 默认构造
    Employee() : id(++count), name("") {}

    void print(){
        cout << id << '\n';
    }

    // 禁止拷贝
    Employee(const Employee& e) = delete;
    Employee& operator= (const Employee& e) = delete;

private:
    string name;
    int id;
    static int count;// 带有类内初始值设定项的成员必须为常量C/C++(1592)
};
int Employee::count = 0;

int main(int argc, char const *argv[])
{
    Employee e1;
    e1.print();
    Employee e2;
    e2.print();
    Employee e3;
    e3.print();
    Employee e4;
    e4.print();
    
    return 0;
}
