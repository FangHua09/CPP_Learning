/*
假设已有上题变量，判断语句合法
int i, *const cp;
int *p1, *const p2;
const int ic, &r = ic;
const int *const p3;
const int *p;

(a) i = ic;
(b) p1 = p3;不能把带底层 const 的指针赋值给无底层 const 指针。会绕开 const 保护修改 const 对象。
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;指针本身 const，不能修改指向。
(f) ic = *p3;

(a) `i = ic;` ✅合法把 const int 变量 ic 的值拷贝给普通 int i；只是拷贝值，不修改 ic。

(b) `p1 = p3;` ❌非法`p1`：`int*`普通指针；`p3`：`const int *const`，带有底层 const。不能把带底层 const 的指针赋值给无底层 const 指针。会绕开 const 保护修改 const 对象。

(c) `p1 = &ic;` ❌非法`&ic`是`const int*`；`p1`是`int*`。不能把 const 对象地址赋给普通指针。

(d) `p3 = &ic;` ❌非法`p3`是`*const`，**指针本身是 const，指针指向不能修改**，不能重新赋值。

(e) `p2 = p1;` ❌非法`p2`是`int *const`，指针本身 const，不能修改指向。

(f) `ic = *p3;` ❌非法`ic`是`const int`常量，不能被赋值修改。

✅只有 (a) 合法，其余全部非法。

> 
> const 指针记忆口诀：

1. **顶层 const**：指针 / 变量本身不能改 → 不能赋值；创建必须初始化。
2. **底层 const**：指向内容不能通过指针修改 → 不能赋值给不带底层 const 的指针。
*/