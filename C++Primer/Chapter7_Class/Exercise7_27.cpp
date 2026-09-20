// 给 Screen 添加`move`、`set`、`display`，使用题目给出测试代码验证。
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
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

    // move函数，以及两个重载的get函数
    Screen &move(pos r, pos c);

    char get() const;

    char get(pos r, pos c) const;

    // 两个重载的set函数
    Screen &set(char ch);

    Screen &set(pos r, pos c, char ch);

    // 两个根据对象是否常量重载的display函数
    Screen &display(ostream &os);

    const Screen &display(ostream &os) const;

private:
    // 提供类内初始值
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;

    // do_display工具函数 (为什么不直接使用cout，因为方便传入不同的流参数)
    void do_display(ostream &os) const
    {
        os << contents;
    }
};

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline char Screen::get() const
{
    return contents[cursor];
}

inline char Screen::get(pos r, pos c) const
{
    return contents[r * width + c];
}

inline Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

inline Screen& Screen::display(ostream& os) {
    do_display(os);// 这里会发生this的隐式转换，转换成指向常量对象的指针,因为do_display是常量成员函数
    return *this;
} 

inline const Screen& Screen::display(ostream& os) const{
    do_display(os); 
    return *this; //这里传递回去常量引用
} 

int main()
{
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    return 0;
}
