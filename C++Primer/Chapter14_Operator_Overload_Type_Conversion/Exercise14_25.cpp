/*
 *练习 14.25：Book 是否需要其他赋值运算符？
 可以增加：Book& operator=(const string& isbn)，把 ISBN 字符串赋值给 Book 对象，清空书名和价格。
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

class Book
{
    Book &operator=(const string &isbn);

public:
    Book(string isbn = "", string name = "", double price = 0)
        : isbn(isbn), name(name), price(price) {}

private:
    string isbn;
    string name;
    double price;
};

Book &Book::operator=(const string &isbn)
{
    this->isbn = isbn;
    name = "unknow";
    price = 0.0;
    return *this;
}