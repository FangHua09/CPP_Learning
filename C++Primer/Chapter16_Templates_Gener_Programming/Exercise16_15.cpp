/*
 *习 16.15：为 Screen 模板实现输入输出运算符，友元说明
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

template <unsigned H, unsigned W>
class Screen
{
public:
    // 非成员友元函数
    friend ostream &operator<< <H, W>(ostream &os, const Screen<H, W> &);
    friend istream &operator>> <H, W>(istream &is, Screen<H, W> &);

    Screen() : contents(H * W, ' ') {}
    char get() const { return contents[cursor]; }
    // 这是移动cursor的 而对于屏幕的高宽编译器已经确定
    char get(unsigned r, unsigned c) const;
    Screen &move(unsigned r, unsigned c);
    /// 模板参数H,W编译期确定屏幕高度宽度，实例化：Screen<24,80> scr;

private:
    unsigned cursor = 0;
    string contents;
};

// 输出 输入
template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &s)
{
    os << s.contents;
    return os;
}
template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &s)
{
    is >> s.contents;
    return is;
}