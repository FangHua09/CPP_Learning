/*
 *原始 D1 里只有fcn(int)；它没有覆盖基类无参虚函数fcn()。
 派生类作用域规则：派生类定义同名函数，会隐藏基类所有同名函数，哪怕参数列表不一样。
 第一问：D1 要覆盖继承来的fcn()，如何修改？
 需要在 D1 中定义和 Base 的 fcn 完全匹配（函数名、参数、返回值） 的版本，加上override做编译期校验：
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

class Base
{
public:
    // 基类虚函数
    virtual int fcn()
    {
        cout << "Base::fcn()" << endl;
        return 1;
    }
};

class D1 : public Base
{
public:
    // 这个fcn(int) 和基类fcn()参数不一样，**只是重载，不是覆盖！**
    // int fcn(int) { cout << "D1::fcn(int)" << endl; return 2; }
    // 覆盖基类虚函数
    int fcn() override
    {
        cout << "D1::fcn()" << endl;
        return 1;
    }
    // 是D1的新虚函数 在Base中不可见
    virtual void f2() { cout << "D1::f2()" << endl; }
};
/*
修改之后，该节原来的调用语句如何解析？
原书上的调用：

Base bobj;
Base *bp1 = &bobj;
D1 d1obj;
Base *bp2 = &d1obj;

bp1->fcn();
bp2->fcn();
d1obj.fcn();
d1obj.fcn(10);

修改之后（D1 已经重写fcn()）
bp1->fcn();：bp1指向 Base 对象，虚函数动态绑定，调用Base::fcn()
bp2->fcn();：bp2是 Base*，但指向 D1 对象，虚函数动态绑定，调用D1::fcn() ✅（这就是覆盖带来的多态）
d1obj.fcn();：D1 对象，直接调用 D1::fcn ()
d1obj.fcn(10);：调用 D1::fcn (int)
对比修改之前：修改前 D1 没有无参 fcn，bp2->fcn()调用 Base::fcn ()；修改后 D1 重写了无参虚函数，bp2->fcn()会调用 D1 版本。
核心考点总结
派生类里同名但参数不同的函数，不会覆盖基类虚函数，只会隐藏基类同名函数。
想要覆盖（override）虚函数，函数签名（名字 + 参数）必须匹配，返回值满足协变规则。
一旦成功覆盖，基类指针 / 引用调用这个虚函数时，发生动态绑定，执行派生类版本。
*/
