/*
练习 5.15：找出 for 循环错误，说明含义并改正

(a)
for (int ix = 0; ix != sz; ++ix) {}
    if (ix != sz)
        // ...
错误：int ix定义在for的初始化部分，ix 的作用域只在 for 循环内部，循环结束 ix 就销毁，外面if(ix != sz)访问ix编译报错。
含义：本意用 ix 遍历，循环结束后再拿 ix 的值做判断。
修改方案：把ix定义放到 for 循环外面
int ix;
for (ix = 0; ix != sz; ++ix) {  }
if (ix != sz)
    // ...

(b)
int ix;
for (ix != sz; ++ix) {  }
错误：for语法：for(初始化;条件;表达式)，第一个是初始化语句，这里写了表达式ix != sz，缺少初始化。
分号数量不对，for 三个部分用两个分号隔开。
这里只有一个分号，编译器把ix != sz当作初始化，++ix当作循环条件，缺少循环条件部分。
本意：ix从某个初值开始，循环条件ix != sz，每次++ix。
修正：
int ix = 0;
for (; ix != sz; ++ix) {}

(c)
for (int ix = 0; ix != sz; ++ix, ++sz) {  }
错误：循环条件ix != sz，循环每轮ix++同时sz++；两个变量同时增长，ix永远追不上sz，无限死循环。
含义：本意遍历容器下标 0~sz‑1，但错误地在每次迭代增大 sz。
修正，不要修改 sz：
for (int ix = 0; ix != sz; ++ix) {  }
*/