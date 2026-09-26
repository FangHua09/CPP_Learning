/*
 *练习 14.17：7.40 的类（继续用 Book 举例）
 Book 类：isbn、书名、价格。应该提供相等运算符。两本书相等：isbn 相同、书名相同、价格相同。
 */

#include <iostream>
#include <string>
using namespace std;

class Book
{
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