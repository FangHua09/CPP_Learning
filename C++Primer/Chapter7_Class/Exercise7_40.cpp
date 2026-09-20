/*
选择 Employee（员工类）
需要的数据成员
std::string id：员工工号
std::string name：员工姓名
double salary：工资
std::string department：部门

构造函数
#include <string>
class Employee
{
private:
    std::string id;
    std::string name;
    double salary;
    std::string department;
public:
    // 默认构造函数
    Employee() = default;

    // 完整信息构造：全部信息给出
    Employee(std::string i, std::string n, double s, std::string dep)
        : id(i), name(n), salary(s), department(dep) {}

    // 只提供工号姓名，工资、部门默认
    Employee(std::string i, std::string n)
        : id(i), name(n), salary(0), department("unknown") {}
};

设计原因
默认构造：允许定义对象不给参数，方便容器使用。
全参构造：完整创建一个有效员工对象。
部分参数构造：有些场景只知道工号姓名，其余信息后续补充，给合理默认值。
其他选项 (a) Book / (b) Date 思路一样：找出实体属性，提供默认构造、全参构造、部分参数构造。
*/