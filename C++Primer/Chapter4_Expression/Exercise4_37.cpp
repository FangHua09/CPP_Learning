/*
**【题目描述】**：
用 C++ 命名强制类型转换（`static_cast`/`const_cast`/`reinterpret_cast`）改写旧式 C 风格强制转换。
变量定义：
int i; double d; const string *ps; char *pc; void *pv;

(a) pv = (void*)ps;--------> pv = reinterpret_cast<void*>(ps)
(b) i = int(*pc);--------------->i = static<int>(*pc)
(c) pv = &d;-----------> pv = static<void*>(d)
(d) pc = (char*) pv; --------------> pc = reinterpret_cast<char*>(pv)
*/