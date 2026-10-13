/*
 *练习 16.3：对两个 Sales_data 调用 compare，观察实例化错误
 Sales_data 默认没有重载<运算符。
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

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    /*
    模板本身只做语法检查，只有实例化时才会检查依赖名称（这里的a < b）；
    const T& a 是常量引用，只能调用标记const的成员函数；
    成员比较运算符 operator< 作为成员函数，必须加末尾 const，否则标准容器 / 泛型算法几乎都不能用；
    std::string 不能直接赋值整数，类型严格区分。
    */
    bool operator<(const Sales_data &rhs) const
    {
        return bookNo < rhs.bookNo;
    }
};

template <typename T>
bool compare(const T &a, const T &b) { return a < b; }

int main()
{
    Sales_data a;
    a.bookNo = "1";
    a.revenue = 1;
    a.units_sold = 1;

    Sales_data b;
    b.bookNo = "2";
    b.revenue = 1;
    b.units_sold = 1;

    cout << compare(a, b); // 编译报错！
}
/*
错误原因：实例化compare<Sales_data>的时候，代码要执行a < b，但 Sales_data 没有定义<，编译器在实例化阶段报运算符不存在。
✅ 关键点：模板的错误很多时候只在实例化阶段才检测，不是模板定义时。
*/