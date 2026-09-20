// 沿用 7.40 的`Employee`员工类，改造为委托构造函数版本。
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

    // 只提供工号姓名，工资、部门默认(委托三参数构造)
    Employee(std::string i, std::string n)
        : Employee(i, n, 0, "unknow") {}
};