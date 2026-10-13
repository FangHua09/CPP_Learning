/*
 *编写Basket购物篮类，存放shared_ptr<Quote>（支持多态，存放 Quote/Bulk_quote），实现添加书籍、计算购物篮总价的功能。
 知识点：多态 + shared_ptr，容器保存智能指针，调用虚函数net_price自动匹配派生类版本。
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

    // 定义俩虚函数
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(move(*this)); }

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

// 支持动态绑定打印工具函数
double print_total(ostream &os, Quote &item, size_t n)
{
    auto ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total: " << ret << endl;
    return ret;
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

    // 覆盖俩虚函数
    Bulk_quote *clone() const & { return new Bulk_quote(*this); }
    Bulk_quote *clone() && { return new Bulk_quote(move(*this)); }

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

class Basket
{
public:
    // Basket():items(Compare){}
    /*
    clone() 返回的类型是 Quote*（裸指针）
    而 make_shared<T>(args) 的作用：在堆上新建一个 T 对象，把 args 作为构造函数参数传给 T 的构造函数。
    你现在传给它一个裸指针 Quote*，编译器尝试调用 Quote(Quote*)，但是你没有这个构造函数，直接报错！
    ❌ 错误理解：make_shared<Quote>(裸指针) 不是把裸指针包装成 shared_ptr！
    ✅ make_shared：分配内存 + 构造对象。
    ✅ 想要把已有裸指针包装成 shared_ptr，要用 shared_ptr<Quote>(item.clone())
    */
    void add_item(const Quote &item)
    {
        items.insert(shared_ptr<Quote>(item.clone()));
    }
    void add_item(Quote &&item)
    {
        items.insert(shared_ptr<Quote>(move(item).clone()));
    }

    double total_receipt(ostream &os)
    {
        double total = 0.0;
        for (auto beg = items.begin(); beg != items.end(); beg = items.upper_bound(*beg))
        {
            total += print_total(os, **beg, items.count(*beg));
        }
        os << "Total sale ： " << total << endl;
        return total;
    }

private:
    // 排序工具函数
    static bool Compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }

    /*
    但是！类内不能用还没定义的成员做模板参数 / 初始化器。
    当编译器读到这行 items 定义的时候，Compare 虽然写在上面，但在类的完整定义结束前，Compare 的地址不能拿来直接初始化成员。
    这是核心编译错误。
    */
    multiset<shared_ptr<Quote>, decltype(Compare) *> items{Compare};
};

int main()
{
    Basket basket;
    // 添加普通书籍
    basket.add_item(Quote("book2", 50));
    // 添加批量折扣书籍Bulk_quote
    basket.add_item(Bulk_quote("book1", 100, 5, 0.2));

    double total = basket.total_receipt(cout);
    cout << "购物篮总价（每本购买10本）：" << total << endl;
    return 0;
}
/*
ISBN: book1 # sold: 1 total: 100
ISBN: book2 # sold: 1 total: 50
Total sale ： 150
购物篮总价（每本购买10本）：150
*/