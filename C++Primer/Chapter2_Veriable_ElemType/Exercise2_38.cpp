/*
> **题目描述**：说明由 decltype 指定类型和由 auto 指定类型有何区别。请举出一个例子，decltype 指定的类型与 auto 指定的类型一样；再举一个例子，decltype 指定的类型与 auto 指定的类型不一样。

**解析**

### 二者区别

1. `auto`：根据**初始化器的值**推导类型；会自动丢弃**顶层 const、引用**；变量必须提供初始化。
2. `decltype(expr)`：直接根据**表达式本身的类型**推导；完整保留 const、引用属性；不需要初始化；
   - 变量加括号`(var)`会得到引用；
   - 赋值表达式返回左值引用；表达式不会实际运行。
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

int main(int argc, char const *argv[])
{
    // ### 例子 1：auto 和 decltype 得到相同类型

    int i = 10;
    auto j = i;
    decltype(i) k = i;

    // ### 例子 2：auto 和 decltype 得到不同类型
    int i = 10;
    auto x = (i);        // auto：int
    decltype((i)) y = i; // decltype：int&

    const int ci = 100;
    auto m = ci;         // auto忽略顶层const → int
    decltype(ci) n = ci; // decltype保留const → const int

    int a = 1, b;
    auto v = (b = a);      // auto：int
    decltype(b = a) w = b; // decltype：int &

    return 0;
}
