/*
编写 Screen 类

>
> Screen 保存屏幕尺寸、光标位置、屏幕内容；提供 move、set、display 成员函数
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