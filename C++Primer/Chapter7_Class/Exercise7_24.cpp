/*
给 Screen 添加 3 个构造函数

1. 默认构造函数
2. 接收宽、高，contents 初始化为若干空格
3. 接收宽、高、初始化字符
*/

#include <iostream>
#include <vector>
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

using namespace std;

class Screen
{
public:
    using pos = string::size_type;

    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' '){}

    //move函数，以及两个重载的get函数
    Screen& move(pos r, pos c);

    char get() const;

    char get(pos r, pos c) const;

private:
    //提供类内初始值
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;
};

inline Screen& Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline char Screen::get() const{
    return contents[cursor];
}

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}