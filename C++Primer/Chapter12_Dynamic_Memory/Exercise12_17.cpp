/*
题目：下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
cpp
运行
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());

(a) IntP p0(ix); ❌非法
unique_ptr构造参数需要指针，ix是int值，类型不匹配，编译报错。
(b) IntP p1(pi); ❌编译通过，但运行时灾难
pi指向栈上局部变量ix，不是堆new出来的内存。unique_ptr析构时会对这个栈指针执行delete，对栈内存delete → 未定义行为，程序崩溃。
(c) IntP p2(pi2); ✅语法合法
pi2是new int(2048)得到的堆指针。p2接管这块堆内存；p2销毁时自动delete内存。
⚠️隐患：裸指针pi2还存在，如果后续继续使用pi2会变成野指针。
(d) IntP p3(&ix); ❌编译通过，运行灾难
&ix是栈对象地址。unique_ptr析构时调用delete释放栈内存，非法。
(e) IntP p4(new int(2048)); ✅合法，推荐写法
直接传入new堆内存，unique_ptr管理堆内存，析构自动释放。
(f) IntP p5(p2.get()); ❌编译通过，运行灾难
p2.get()返回裸指针，p5用这个裸指针构造新unique_ptr。现在p2和p5两个独立unique_ptr同时拥有同一块堆内存。两个智能指针离开作用域时都会执行delete，重复释放 (double free)，程序崩溃。
*/

