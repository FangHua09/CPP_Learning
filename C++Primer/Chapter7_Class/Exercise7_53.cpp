// 教材示例 Debug 类，含有`constexpr`构造函数，保存三类调试标志位，`set_*`修改成员，`any()`判断是否开启调试。
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

class Debug
{
public:
    // constexpr构造函数
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {} // constexpr必须初始化所有数据成员(使用初始值列表)
    constexpr Debug(bool hw, bool io, bool other) : hw(hw), io(io), other(other) {}

    // constexpr成员函数
    constexpr bool any()
    {
        return hw || io || other;
    }

    // 普通成员函数
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_io(bool b)
    {
        io = b;
    }
    void set_other(bool b)
    {
        other = b;
    }

private:
    bool hw;
    bool io;
    bool other;
};