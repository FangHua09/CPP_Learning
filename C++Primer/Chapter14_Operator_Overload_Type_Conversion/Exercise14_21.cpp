/*
 *练习 14.21：反过来：+做实际加法，+=调用+

 缺点分析
 性能差：+=本来可以就地修改对象；现在*this + rhs会生成临时对象，再赋值给*this，多一次对象拷贝。
 语义逻辑颠倒：复合赋值是基础操作，普通加法应该复用复合赋值。
 当类型内存开销大时，临时对象的开销会很明显。
 教材推荐：+=写核心逻辑，+复用+=。
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
    Sales_data &operator+=(const Sales_data &rhs);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// + 完成加法逻辑

// 如果没得+= 则必须额外创建
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    if (lhs.bookNo != rhs.bookNo)
        throw runtime_error("different bookNo");
    Sales_data sum;
    sum.bookNo = lhs.bookNo;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

// += 调用 +
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    *this = *this + rhs;
    return *this;
}
