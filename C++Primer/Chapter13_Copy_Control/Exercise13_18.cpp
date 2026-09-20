/*
题目：定义 Employee 类，包含姓名 string、唯一雇员证号；默认构造、接收姓名 string 的构造函数；用 static 成员自动生成唯一证号。
count是静态成员，属于整个类，所有对象共享。
每次构造新对象，++count分配独一无二的雇员 id
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
