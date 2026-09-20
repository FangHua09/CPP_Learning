
#include <iostream>
using namespace std;

// =========版本1：13.14 使用合成拷贝构造=========
class numbered_14
{
public:
    numbered_14() : mysn(++count) {}
    int mysn;

private:
    static int count;
};
int numbered_14::count = 0;
void f_14(numbered_14 s) { cout << s.mysn << endl; }

// =========版本2：13.15 自定义拷贝构造，拷贝生成新编号=========
class numbered_15
{
public:
    numbered_15() : mysn(++count) {}
    numbered_15(const numbered_15 &) : mysn(++count) {} // 拷贝构造分配新序号
    int mysn;

private:
    static int count;
};
int numbered_15::count = 0;
void f_15(numbered_15 s) { cout << s.mysn << endl; }

// =========版本3：13.16，参数改为const引用=========
void f_16(const numbered_15 &s) { cout << s.mysn << endl; }

int main()
{
    cout << "=====练习13.14 合成拷贝，值传递=====\n";
    numbered_14 a14, b14 = a14, c14 = b14;
    f_14(a14);
    f_14(b14);
    f_14(c14);

    cout << "\n=====练习13.15 自定义拷贝构造，值传递=====\n";
    numbered_15 a15, b15 = a15, c15 = b15;
    f_15(a15);
    f_15(b15);
    f_15(c15);

    cout << "\n=====练习13.16 自定义拷贝构造，引用传递=====\n";
    numbered_15 a16, b16 = a16, c16 = b16;
    f_16(a16);
    f_16(b16);
    f_16(c16);
    return 0;
}
