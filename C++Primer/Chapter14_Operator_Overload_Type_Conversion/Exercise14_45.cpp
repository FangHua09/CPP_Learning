/*
 *编写类型转换运算符，将Sales_data对象转成string和double；返回值是什么。假设Sales_data成员：bookNo(ISBN string)，units_sold销量，revenue收入。
 转string：返回书籍编号bookNo
 转double：返回平均售价 revenue / units_sold
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

class Sales_data
{
public:
    // ...其他成员
    operator string() const {
        return bookNo;
    }
    operator double() const {
        if (units_sold == 0) return 0;
        return revenue / units_sold;
    }
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};