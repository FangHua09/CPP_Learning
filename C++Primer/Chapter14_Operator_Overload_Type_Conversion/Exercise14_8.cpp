/*
 *练习 14.8：7.40 的类，选 Book 举例（C++Primer 7.40）
 */
#include <iostream>
#include <string>
using namespace std;

class Book
{
    friend ostream& operator<<(ostream& os, const Book& b);
public:
    Book(string isbn, string name, double price)
        : isbn(isbn), name(name), price(price) {}
private:
    string isbn;
    string name;
    double price;
};

ostream& operator<<(ostream& os, const Book& b)
{
    os << b.isbn << " \"" << b.name << "\" " << b.price;
    return os;
}

