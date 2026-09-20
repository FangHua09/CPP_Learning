/*
p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：

auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
process形参：shared_ptr<int>
知识点：shared_ptr 构造函数是explicit

解答
(a) process(sp); ✅合法
拷贝sp，引用计数 + 1；函数结束副本销毁，计数 - 1。
(b) process(new int()); ✅语法合法（不推荐）
new int()裸指针，显式构造临时 shared_ptr传入。函数结束临时对象销毁，释放内存。
不能隐式转换，但可以直接用裸指针显式构造临时对象传参。
(c) process(p); ❌不合法
shared_ptr 的单参数裸指针构造函数是explicit，裸指针不能隐式转换成 shared_ptr，编译报错。
(d) process(shared_ptr<int>(p)); ✅语法合法，但危险
用裸指针p显式构造临时 shared_ptr。函数结束临时对象析构，delete释放 p 指向内存。后续裸指针p变成野指针，再次使用会出问题。
*/

