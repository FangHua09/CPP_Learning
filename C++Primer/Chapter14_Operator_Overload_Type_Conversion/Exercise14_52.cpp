/*

1）ld = si + ld;
表达式：si + ld，左操作数SmallInt si，右操作数LongDouble ld
第一步：找候选函数
候选集合来源：
成员运算符：LongDouble::operator+(const SmallInt&)
成员运算符等价于：operator+(LongDouble* this, const SmallInt&)
第一个参数必须是 LongDouble 类型（this 指针绑定左操作数），但左操作数是 SmallInt，直接排除。
非成员：LongDouble operator+(LongDouble&, double);
参数要求：第一个参数LongDouble&，第二个double。
第二步：检查是否可行
要匹配operator+(LongDouble&, double)：
左操作数 si(SmallInt) → 转换成LongDouble：
需要：si → int（operator int()，类类型转换），然后int → double内置转换，再double → LongDouble（构造函数，第二次类类型转换）。
C++ 重载规则：一次调用最多允许一次用户自定义（类）类型转换，两次用户自定义转换不允许。
因此这条函数不可行。
✅ 结论：没有可行函数。si + ld 编译报错。


2）ld = ld + si;
表达式：ld + si，左操作数LongDouble ld，右操作数SmallInt si
候选函数
成员：LongDouble operator+(const SmallInt&);
等价：ld.operator+(si)
非成员：LongDouble operator+(LongDouble&, double);
可行函数判定
成员版本 ld.operator+(const SmallInt&)
左：ld（LongDouble 对象，精确匹配 this）；右：si → const SmallInt&，精确匹配，无任何转换。✅可行。
非成员版本 operator+(LongDouble&, double)
左：ld 精确匹配LongDouble&；
右：si 需要调用operator int()转为 int，再内置转换 int→double。需要一次类类型转换。✅可行。
最佳可行函数对比
成员版本：第二个参数精确匹配
非成员版本：第二个参数需要类型转换
精确匹配优先级高于需要转换，选择成员LongDouble::operator+(const SmallInt&)

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

// SmallInt
class SmallInt {
public:
    SmallInt(int = 0);               // int → SmallInt 转换构造
    operator int() const { return val; } // SmallInt → int 类型转换
private:
    std::size_t val;
};

// LongDouble
struct LongDouble {
    LongDouble(double = 0.0);        // double → LongDouble 转换构造
    operator double();               // LongDouble → double
    operator float();                // LongDouble → float
    // 成员operator+
    LongDouble operator+(const SmallInt&);
};
// 非成员
LongDouble operator+(LongDouble&, double);

SmallInt si;
LongDouble ld;
// ld = si + ld;
// ld = ld + si;
