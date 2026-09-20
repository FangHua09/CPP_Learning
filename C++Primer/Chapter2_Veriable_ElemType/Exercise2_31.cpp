/*
基于上面声明，判断合法性，分析顶层 / 底层 const
- `v2`：顶层 const int
- `r1`：普通`int&`绑定`v1`
- `p1`：`int*`（无底层 const）
- `p2`：`const int*`（底层 const，指针本身可修改）
- `p3`：`const int *const`（顶层 + 底层 const）

r1 = v2;//
p1 = p2; p2 = p1;
p1 = p3; p2 = p3;

r1 = v2; ✅合法
把v2的值拷贝赋值给r1（即v1）。
r1是普通引用；赋值只是拷贝值，不是修改引用绑定。v2的顶层 const 只保护 v2 本身，拷贝值不受影响。

p1 = p2; ❌非法
p1：int*（没有底层 const）；p2：const int*（带有底层 const）。
不能把带底层 const 的指针赋值给不带底层 const 指针；会产生可以修改 const 对象的途径。
底层 const 限制：不能丢掉底层 const 属性。

p2 = p1; ✅合法p2是底层 const 指针（指针本身可修改指向）。普通int*可以赋值给const int*；相当于给指向对象增加一层保护，允许。

p1 = p3; ❌非法
p3既有顶层 const (指针不可改)，又有底层 const。赋值时顶层 const 会被忽略，但p3携带底层 const；p1没有底层 const，不能赋值。

p2 = p3; ✅合法p3的顶层 const（指针本身不能改）在赋值时丢弃；保留底层 const。p2本身就是底层 const 指针，类型匹配，可以接收 p3 存的地址。

拷贝赋值时，顶层 const 可以忽略；底层 const 不能随便丢掉。
两个指针赋值，若源有底层 const，目标也必须有底层 const。
*/