/*
 *练习 16.14：Screen 类模板，非类型参数指定高、宽
 非类型模板参数：编译期常量，不是类型，是值。
 */
template <unsigned H, unsigned W>
class Screen
{
public:
    Screen() : contents(H * W, ' ') {}
    char get() const { return contents[cursor]; }
    char get(unsigned r, unsigned c) const;
    Screen &move(unsigned r, unsigned c);
    /// 模板参数H,W编译期确定屏幕高度宽度，实例化：Screen<24,80> scr;
    
private:
    unsigned cursor = 0;
    string contents;
};