/*
聚合类条件（C++11）：
所有成员public
没有类内初始值
没有用户定义构造函数
无基类、无 virtual 函数
原始版本中units_sold = 0;、revenue = 0.0;写了类内初始值，因此不再是聚合类，不能使用花括号聚合初始化，上面这条语句编译报错。
聚合初始化语义本意：依次把列表值赋给成员：bookNo = "978‑0590353403"，units_sold = 25，revenue = 15.99；但是因为不是聚合类，语法不允许。
*/
#include <iostream>
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

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold; // 类内初始值
    double revenue;      // 类内初始值
};

int main(int argc, char const *argv[])
{
    Sales_data item = {"978‑0590353403", 25, 15.99};

    return 0;
}
