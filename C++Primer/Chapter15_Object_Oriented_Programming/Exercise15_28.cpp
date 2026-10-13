/*练习 15.28：vector<Quote>，存入 Bulk_quote 对象
vector<Quote> 保存的是Quote 类型的实体对象，不是引用 / 指针。当你把Bulk_quote对象放进这个 vector 时，会发生对象切片：派生类Bulk_quote独有的成员（min_qty、discount）被直接切掉，只保留基类Quote部分，存入 vector。调用net_price时，只能调用Quote::net_price，不会调用派生类的折扣版本，没有多态。
 *
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
    Quote()
    {
        // cout << "【Quote 默认构造】" << endl;
    }

    Quote(const string &s, double price) : bookNo(s), price(price)
    {
        // cout << "【Quote 普通构造】 bookNo=" << bookNo << endl;
    }
    // （拷贝构造、拷贝赋值、移动构造、移动赋值、析构）
    Quote(const Quote &orig) : bookNo(orig.bookNo), price(orig.price)
    {
        // cout << "【Quote 拷贝构造】" << endl;
    }
    Quote(Quote &&orig) : bookNo(move(orig.bookNo)), price(orig.price)
    {
        // cout << "【Quote 移动构造】" << endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        // cout << "【Quote 拷贝赋值】" << endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        // cout << "【Quote 移动赋值】" << endl;
        bookNo = move(rhs.bookNo);
        price = rhs.price;
        return *this;
    }
    virtual ~Quote()
    {
        // cout << "【Quote 析构】" << endl;
    }

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }
    virtual ostream &debug(ostream &os) const
    {
        os << "Quote: bookNo=" << bookNo << ", price=" << price << endl;
        return os;
    }

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
    Bulk_quote() : Quote(), min_qty(0), discount(0.0)
    {
        // cout << "【Bulk_quote 默认构造】" << endl;
    }
    Bulk_quote(const string &bookNo, double price, size_t min_qty, double discount) : Quote(bookNo, price), min_qty(min_qty), discount(discount)
    {
        // cout << "【Bulk_quote 普通构造】" << endl;
    }

    Bulk_quote(const Bulk_quote &orig) : Quote(orig), discount(orig.discount), min_qty(orig.min_qty)
    {
        // cout << "【Bulk_quote 拷贝构造】" << endl;
    }
    Bulk_quote(Bulk_quote &&orig) : Quote(move(orig)), min_qty(orig.min_qty), discount(orig.discount)
    {
        // cout << "【Bulk_quote 移动构造】" << endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        // cout << "【Bulk_quote 拷贝赋值】" << endl;
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }
    Bulk_quote &operator=(Bulk_quote &&rhs)
    {
        // cout << "【Bulk_quote 移动赋值】" << endl;
        Quote::operator=(move(rhs));
        discount = rhs.discount;
        min_qty = rhs.min_qty;
        return *this;
    }
    ~Bulk_quote()
    {
        // cout << "【Bulk_quote 析构】" << endl;
    }
    // 覆盖纯虚函数
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

    // 覆盖纯虚函数
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

// 测试程序
int main()
{
    vector<Quote> vec;
    // 放入Bulk_quote对象，发生切片
    vec.push_back(Bulk_quote("book1", 100, 5, 0.2));
    vec.push_back(Quote("book2", 50));

    double total;
    for (auto &&i : vec)
    {
        total += i.net_price(10); // 只能调用Quote::net_price，Bulk_quote折扣丢失！
    }
    cout << "total = " << total << endl;
    return 0;
}