/*
 *为 Quote 类体系添加 debug 虚函数，显示每个类的数据成员
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

    virtual double net_price(size_t n) const { return n * price; }
    virtual ostream &debug(ostream &os) const
    {
        os << "Quote: bookNo=" << bookNo << ", price=" << price << endl;
        return os;
    }
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

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &bookNo, double price, size_t min_qty, double discount) : Quote(bookNo, price), min_qty(min_qty), discount(discount) {}

    // 覆盖虚函数
    // 如果大于了min_qty最低打折购买量 就打折
    double net_price(size_t n) const override
    {
        if (n > min_qty)
        {
            return (1 - discount) * n * price;
        }
        else
            return price * n;
    }

    // 覆盖虚函数
    // 显示自己的成员
    ostream &debug(ostream &os) const override
    {
        Quote::debug(os); // 对于基类自己的成员通过调用基类的函数来获取
        os << "Bulk_quote: min_qty=" << min_qty << ", discount=" << discount << endl;
        return os;
    }

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_quote : public Quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &bookNo, double price, size_t max_qty, double discount) : Quote(bookNo, price), max_qty(max_qty), discount(discount) {}
    double net_price(size_t n) const override
    {
        if (n < max_qty)
        {
            return n * price * discount;
        }
        else
            return n * price;
    }
    // 覆盖虚函数
    // 显示自己的成员
    ostream &debug(ostream &os) const override
    {
        Quote::debug(os); // 对于基类自己的成员通过调用基类的函数来获取
        os << "Limit_quote: max_qty=" << max_qty << ", discount=" << discount << endl;
        return os;
    }

private:
    size_t max_qty = 0;
    double discount = 0.0;
};