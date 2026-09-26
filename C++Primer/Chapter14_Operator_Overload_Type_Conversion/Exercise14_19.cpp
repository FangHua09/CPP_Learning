/*
 *✅ 可以实现关系运算符，一般以 isbn 作为比较依据（图书编号字典序）
 */

#include <iostream>
#include <string>
using namespace std;

class Book
{
    friend bool operator<(const Book &lhs, const Book &rhs);
    friend bool operator>(const Book &lhs, const Book &rhs);
    friend bool operator<=(const Book &lhs, const Book &rhs);
    friend bool operator>=(const Book &lhs, const Book &rhs);

    friend ostream &operator<<(ostream &os, const Book &b);
    friend istream &operator>>(istream &is, Book &b);

    friend bool operator==(const Book &lhs, const Book &rhs);
    friend bool operator!=(const Book &lhs, const Book &rhs);

public:
    Book(string isbn = "", string name = "", double price = 0.0)
        : isbn(isbn), name(name), price(price) {}

private:
    string isbn;
    string name;
    double price;
};

ostream &operator<<(ostream &os, const Book &b)
{
    os << b.isbn << " \"" << b.name << "\" " << b.price;
    return os;
}

istream &operator>>(istream &is, Book &b)
{
    string isbn, name;
    double price;
    is >> isbn >> name >> price;
    if (is)
    { // 写入成功了再写入对象内存
        b.isbn = isbn;
        b.name = name;
        b.price = price;
    }
    else
    {
        b = Book();
    }
    return is;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.isbn == rhs.isbn && lhs.name == rhs.name && lhs.price == rhs.price;
}
bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.isbn < rhs.isbn; // 按书号字典序排序
}
bool operator>(const Book &lhs, const Book &rhs)
{
    return rhs < lhs;
}
bool operator<=(const Book &lhs, const Book &rhs)
{
    return !(rhs < lhs);
}
bool operator>=(const Book &lhs, const Book &rhs)
{
    return !(lhs < rhs);
}