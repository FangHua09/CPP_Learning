/*
 *定义 Bulk_quote 类
 Bulk_quote 继承 Quote，达到指定购买数量后，全部书籍享受折扣价。
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

private:
    size_t min_qty = 0;
    double discount = 0.0;
};