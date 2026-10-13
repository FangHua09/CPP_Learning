/*
 *情况 1：形参改为 T val（值传递，不是万能引用）
 值传递会剥离 const、引用(a)g(i)：T=int(b)g(ci)：T=int（const 被丢掉）(c)g(i*ci)：T=int
 
 情况 2：形参改为 const T& val（const 引用）
 引用推断，忽略实参本身的顶层 const(a)g(i)：T=int(b)g(ci)：T=int(c)g(i*ci)：T=int
 小结：T / const T& 这三种调用 T 全部都是int。
 */
