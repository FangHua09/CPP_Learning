/*
 *练习 14.24：Book 是否需要拷贝赋值、移动赋值？
 ✅ 需要。Book 里面只有std::string和double，合成的拷贝 / 移动赋值已经够用，不需要自己写。
 合成拷贝赋值：逐个成员拷贝 isbn、name、price
 合成移动赋值：string 会被移动，效率高
 如果你的类持有裸指针，就必须手动写拷贝控制；Book 没有动态内存，编译器生成版本足够。

 补充 move的作用只是把左值变成右值 让左侧运算对象去调用它的移动赋值运算符 如果左侧有 就移动 如果没有 就constT&拷贝
 其中内置类型不能移动 直接赋值，而string自己实现了移动赋值
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
    friend bool operator==(const Book&, const Book&);
public:
    Book(string isbn="", string name="", double price=0)
        :isbn(isbn), name(name), price(price){}
private:
    string isbn;
    string name;
    double price;
};
