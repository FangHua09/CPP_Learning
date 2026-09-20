/*
# 练习 3.11

> 
> **题目描述**：下面的范围 for 语句合法吗？如果合法，c 的类型是什么？

```
const string s = "Keep out!";
for(auto &c : s){  }
```

**合法。**`s`是`const string`常量字符串。`auto &c`推导出来的类型是：`const char &`，常量字符的引用。

> 
> 因为 s 是 const，所以 c 是 const 引用，你可以读取 c，但是**不能修改 c**。如果在循环体内写`c='x'`就会编译报错。

*/