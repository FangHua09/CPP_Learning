/*
给定下面的 new 表达式，你应该如何释放 pa？int *pa = new int[10];

✅ 答案：必须使用 delete[] pa;
int *pa = new int[10];
// 使用pa ...
delete[] pa;
核心规则
new[]（分配数组） ➜ 必须配对 delete[]
new（单个对象） ➜ 必须配对 delete
❌ 错误写法：delete pa;，这是未定义行为！
原理：delete[]会读取数组长度信息，依次调用每个元素析构函数，再释放整块内存。delete pa只会释放第一个元素，剩余内存泄漏 / 内存损坏。

*/

