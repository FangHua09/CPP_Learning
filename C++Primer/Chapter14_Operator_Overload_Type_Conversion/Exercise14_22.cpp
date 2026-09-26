/*
 *练习 14.22：重载赋值运算符：Sales_data = string
 需求：Sales_data obj; obj = "0-201-99999-9";，把 string 赋值给 bookNo，销量和收入置 0。
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
    Sales_data &operator=(const string &isbn);
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::operator=(const string &isbn)
{
    bookNo = isbn;
    units_sold = 0;
    revenue = 0.0;
    return *this;
}