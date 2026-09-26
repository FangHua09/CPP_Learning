/*
 *练习 14.12：给 Book 类写输入运算符（7.40 选的 Book 类）
 要求：处理输入错误
 */

#include <iostream>
#include <string>
using namespace std;

class Book
{
    friend ostream &operator<<(ostream &os, const Book &b);
    friend istream &operator>>(istream &is, Book &b);

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
