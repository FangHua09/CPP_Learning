/*
 *题目：定义你自己的 Quote 类和 print_total 函数
 题目要求：Quote 基类，表示书籍报价；print_total接收数量和 Quote 引用，打印总价。
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

class Quote
{
public:
    Quote() = default;
    Quote(const string &s, double price) : bookNo(s), price(price) {}

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) { return n * price; }
    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};

void print_total(ostream &os, Quote &item, size_t n)
{
    auto ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total: " << ret << endl;
}

