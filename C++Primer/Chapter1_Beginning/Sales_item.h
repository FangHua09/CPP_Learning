#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <iostream>
#include <string>

class Sales_item {
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, const Sales_item&);
friend bool operator==(const Sales_item&, const Sales_item&);

public:
    Sales_item() : units_sold(0), revenue(0.0) {}
    Sales_item(const std::string &book):
              bookNo(book), units_sold(0), revenue(0.0) {}
    Sales_item(std::istream &is) { is >> *this; }

public:
    Sales_item& operator+=(const Sales_item&);
    std::string isbn() const { return bookNo; }

private:
    std::string bookNo;      // ISBN编号
    unsigned units_sold;     // 销售本数
    double revenue;          // 总销售额
};

inline
bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline
bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs);
}

Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.revenue/s.units_sold;
    return out;
}

#endif
