/*
背景：书店程序：读取销售记录，按 ISBN 合并相同书籍，把汇总结果输出。
argv[1]：输入数据文件名
argv[2]：输出结果文件名
练习 8.7：输出写入文件（覆盖模式）
要求：main 接收命令行参数，第二个参数作为输出文件名，把汇总结果写到该文件。

[运行结果]
PS C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library>
g++ Exercise8_7.cpp -o Exercise8_7.exe -std=c++17

PS C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library>
.\Exercise8_7.exe "Exercise8_6.txt" "Exercise8_7.txt"   //传递两个参数


 PS C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library>
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
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

using namespace std;

// ✅前向声明
//struct Sales_data;

// 非成员函数声明，写在结构体前面，依赖前向声明
//ostream &print(ostream &os, const Sales_data &s);
//istream &read(istream &is, Sales_data &s);

struct Sales_data
{
    // 友元声明：
    friend ostream &print(ostream &os, const Sales_data &s);
    friend istream &read(istream &is, Sales_data &s);
    // 不属于非成员函数（接口函数）
    // // print函数
    // ostream &print(ostream &os, const Sales_data &s);

    // // read函数
    // istream &read(istream &is, Sales_data &s);

    // 接收 ISBN，数量，单价
    Sales_data(const string &bookNo, unsigned units_sold, double price) : bookNo(bookNo), units_sold(units_sold), revenue(price * units_sold)
    {
        //cout << "普通三参数构造" << '\n';
    }

    // 默认构造函数 （前提要为内置类型或者复合类型赋予初始值）（委托给三参数构造）
    Sales_data() : Sales_data("", 0, 0)
    {
        //cout << "默认构造委托三参数构造" << '\n';
    }

    // 只接收 ISBN (委托给三参数构造)
    Sales_data(const string &s) : Sales_data(s, 0, 0)
    {
        //cout << "单string参数构造委托三参数构造" << '\n';
    }

    // 接收`std::istream&` inline (委托给默认构造，默认构造委托给三参数构造)
    Sales_data(istream &is) : Sales_data()
    {
        //cout << "istream流参数构造委托默认构造" << '\n';
        // 复用read函数 但是声明先写上
        read(is, *this); // 把本对象传入
    }

    // add
    Sales_data add(const Sales_data &s1, const Sales_data &s2);

    // 题目描述：向 Sales_data 类添加combine成员函数与isbn成员函数。
    Sales_data &combine(const Sales_data &s);

    string isbn() const
    {
        return bookNo;
    }

private:
    std::string bookNo;      // isbn
    unsigned units_sold = 0; // 售出数量
    double revenue = 0.0;    // 收入
};

// print函数
ostream &print(ostream &os, const Sales_data &s)
{
    os << "书号： " << s.isbn() << " 售卖数量： " << s.units_sold << " 收入 ： " << s.revenue;
    if (s.units_sold != 0)
    {
        os << " 书籍单价： " << s.revenue / s.units_sold;
    }
    else
    {
        os << " " << "0";
    }
    return os;
}

// read函数
istream &read(istream &is, Sales_data &s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return is;
}

// add
Sales_data Sales_data::add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data sum;
    sum = s1;
    sum.combine(s2);
    return sum; // 值拷贝
}

// 类外定义combine函数
Sales_data &Sales_data::combine(const Sales_data &s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}

/*
从一个文件中读取交易记录。将文件名作为一个参数传递给 main。
main(int argc, char *argv[])；argv[1]接收传入文件名。Sales_data 使用书中结构体。
*/
int main(int argc, char const *argv[])
{
    ifstream ifs(argv[1]); // 读入第一个参数（文件名）
    ofstream ofs(argv[2], ofstream::app); // 读入第二个参数 [设置追加]
    // 文件名内有多条书单销售记录，我们通过ifs来替代cin不断读取销售记录
    Sales_data total(ifs);
    if (ifs)
    {
        Sales_data trans;
        while (read(ifs, trans))
        {
            if (trans.isbn() == total.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(ofs, total) << endl;
                total = trans;
            }
        }
        print(ofs, total) << endl;
    }
    else
    {
        cout << "读取失败" << '\n';
    }
}
