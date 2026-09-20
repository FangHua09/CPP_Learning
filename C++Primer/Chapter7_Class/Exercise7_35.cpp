/*
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}

名字查找规则：类作用域名字遮蔽外层作用域
类内部：setVal(Type)、参数Type、Type initVal()，这里的Type是类内 typedef double Type，全局的string Type被遮蔽。
类外实现 Type Exercise::setVal(Type parm)
函数返回类型最前面的Type：此时还没有进入 Exercise 类作用域，用的是全局的 typedef string Type。
参数列表里的Type parm：已经处于Exercise::类作用域，这里的Type是类内 double。

👉 这里直接就出现严重类型不匹配：
函数声明：Exercise::setVal 返回值是类内double
函数定义：返回值被解析成全局std::string
声明返回 double，定义返回 string，类型冲突 → 编译报错。
initVal()：val = parm + initVal();调用的是类的成员函数 Exercise::initVal()，不是全局的initVal()；类内的名字优先，遮蔽全局同名函数。
错误总结
返回类型冲突：声明返回double，外部定义返回string；
val是int，parm(double)+initVal()返回 double，赋值给 int 会发生隐式转换；
成员函数initVal()只有声明，没有函数定义，会链接错误。

修改方案
类外定义的返回类型，显式限定类作用域 Exercise::Type，代表类内的 double 类型。
#include <string>
using std::string;

typedef string Type;
Type initVal();

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

// ✅ 返回类型写 Exercise::Type，使用类内double
Exercise::Type Exercise::setVal(Type parm) {
    val = static_cast<int>(parm + initVal());
    return val;
}

// 补充实现成员initVal，否则链接报错
Exercise::Type Exercise::initVal()
{
    return 0.0;
}


*/