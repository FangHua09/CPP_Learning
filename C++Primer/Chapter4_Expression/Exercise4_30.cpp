/*
【题目描述】：在下列表达式适当位置加上括号，含义与原表达式保持不变。
(a) sizeof x + y
(b) sizeof p->mem[i]
(c) sizeof a < b
(d) sizeof f()

【解答】优先级：->、[] > sizeof > +、<
(a) sizeof优先级高于+ → (sizeof x) + y
(b) ->、[]优先级高于sizeof → sizeof( (p->mem)[i] )
(c) sizeof优先级高于< → (sizeof a) < b
(d) sizeof作用函数调用表达式，不取函数执行结果，取返回类型大小 → sizeof( f() )
补充：sizeof(f())不会调用函数 f，只根据返回值类型计算大小。
*/