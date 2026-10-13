/*
 *练习 15.6：将 Quote 和 Bulk_quote 对象传给 print_total，验证动态绑定
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

int main(int argc, char const *argv[])
{
    Quote base("978-1", 50);
    Bulk_quote bulk("978-2", 50, 10, 0.2); // 满10本，8折
    print_total(cout, base, 20);
    print_total(cout, bulk, 20);
    return 0;
}
