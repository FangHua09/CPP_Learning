/*
ptr：int*；vec：vector<int>；ival：int

(a) ptr != 0 && *ptr++
&&短路；后置++优先级高于*。等价：(ptr != nullptr) && (*(ptr++))
含义：
先判断指针 ptr 不是空指针；
如果 ptr 非空：对 ptr 解引用取当前指向的值；ptr 指针向后移动一个 int 位置。
整个表达式结果：ptr 不为空，并且*ptr（自增前的值）非 0，则为 true。
✅ 表达式合法。逻辑：指针非空，并且指针当前指向的值非 0，同时指针前进。

(b) ival++ && ival
含义：&&短路。
取ival旧值作为左侧判断；然后ival +1。
如果左侧旧值为 true（非 0），再判断已经 + 1 之后的新 ival。
⚠️ 语法合法，但可读性差。举例：ival = 1：左侧1为真，ival 变成 2，再判断2，整体 true。ival = 0：左侧 0，短路，ival 变成 1，右侧不计算。
风险：同一个表达式读取并且修改ival，虽然语法合法，但代码容易混淆，不推荐这么写。

(c) vec[ival++] <= vec[ival]
❌ 表达式语法合法，但行为是未定义行为！原因：C++ 没有规定<=运算符左右操作数的求值顺序。表达式：vec[ival++] <= vec[ival]一边修改ival（ival++），一边读取ival，分布在<=运算符两边。
如果先算左边：vec[旧ival]，ival 自增，再算右边vec[新ival]
如果先算右边：vec[旧ival]，再算左边vec[旧ival]，ival 自增
两种求值顺序得到完全不同结果，标准未指定，属于未定义行为。
✅ 修改：把自增挪到表达式外面
vec[ival] <= vec[ival+1];
++ival;

*/