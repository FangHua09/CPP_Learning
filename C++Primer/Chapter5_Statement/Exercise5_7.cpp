/*
改正代码错误

(a) 原代码

if (ival1 != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
错误：ival1 = ival2语句末尾缺少分号。
修正：
if (ival1 != ival2)
    ival1 = ival2;
else ival1 = ival2 = 0;

(b) 原代码

if (ival < minval)
    minval = ival;
    occurs = 1;
错误：if 后没有花括号。只有minval=ival;属于 if，occurs=1;无论条件真假都会执行。逻辑意图是条件成立时两条都执行。
修正：

if (ival < minval)
{
    minval = ival;
    occurs = 1;
}

(c) 原代码

if (int ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";
错误：ival定义在第一个if条件内，作用域仅限第一个 if，第二个if(!ival)访问不到，编译报错。
修正，把ival提到外面：

int ival = get_value();
if (ival)
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";

(d) 原代码

if (ival = 0)
    ival = get_value();
错误：ival = 0是赋值，不是比较相等。把ival赋值为 0，条件永远为假，ival=get_value()永远不会执行。本意应该判断相等ival == 0。
修正：
if (ival == 0)
    ival = get_value();
*/