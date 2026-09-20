/*
iter：vector<string>::iterator，迭代器指向string对象。运算符优先级：后置++ > -> > 解引用*；.运算符作用于对象，->作用于指针 / 迭代器。
(a) *iter++;
✅ 合法后置++优先级高于*，等价：*(iter++)
iter++：返回迭代器原来的副本，然后迭代器向后移动。
*：对迭代器旧副本解引用，获取指向的string。
含义：获取迭代器当前指向的 string，然后迭代器向后移动一位。

(b) (*iter)++;
❌ 不合法*iter得到迭代器指向的string对象。++递增运算符不能作用于string类型，string 没有定义自增操作，编译报错。

(c) *iter.empty()
❌ 不合法.成员访问优先级高于*。等价：*(iter.empty())iter是迭代器，不是对象，不能直接用.调用成员；.需要作用于对象，迭代器要用->。编译器尝试调用iter.empty()，迭代器没有empty()成员，编译错误。

(d) iter->empty();
✅ 合法iter->empty()等价(*iter).empty()。对迭代器解引用得到 string，调用 string 的empty()成员函数，判断该字符串是否为空。

(e) ++*iter;
❌ 不合法解引用先执行：++(*iter)。*iter得到string对象，string 没有前置自增运算符，不能执行++，编译报错。

(f) iter++->empty();
✅ 合法后置++优先级高于->；等价：(iter++)->empty()
iter++返回迭代器原来的副本，迭代器本身向后移动；
使用旧副本调用->empty()，判断迭代器移动前指向的字符串是否为空。
*/