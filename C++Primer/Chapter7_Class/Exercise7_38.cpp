/*
给接收istream&的构造函数设置默认实参cin
#include <iostream>
class Sales_data
{
public:
    Sales_data(std::istream &is = std::cin);
    // ...其余成员
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

调用时可以写 Sales_data data;，等价于Sales_data data(std::cin);。
*/