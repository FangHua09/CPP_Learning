/*
题目：定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。
⚠️ 关键难点（循环依赖）
Window_mgr 内部保存 vector<Screen>，所以先要前向声明 class Screen，才能定义 Window_mgr 类；
Screen 需要把 Window_mgr::clear 这个成员函数声明为友元，所以必须看见 Window_mgr 的完整类定义；
因此顺序：Screen前向声明 → 定义Window_mgr类 → 定义Screen类（把clear声明为友元） → 之后再实现 Window_mgr::clear 函数（此时 Screen 已经完整定义，可以访问私有成员）。
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

// 前向声明Screen，因为vector用到了Screen，因为vector不计较类有多大，所以无需看到全部定义
class Screen;

class Window_mgr{
    public:
    using ScreenIndex = string::size_type;
    void clean(ScreenIndex i); //仅声明，因为需要用到Screen的私有成员
    private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen
{
public:
    // 友元声明 想要声明友元必须看到整个类的完整定义（类内的成员函数可以仅声明）
    friend void Window_mgr::clean(ScreenIndex i);
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

// 最后才定义clean
void Window_mgr::clean(ScreenIndex i) {
    Screen& s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}