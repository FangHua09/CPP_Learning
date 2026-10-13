/*
 *什么时候静态类型与动态类型不同？
 当表达式是基类的指针或者基类引用，指向 / 绑定一个派生类对象时，静态类型（基类）≠动态类型（派生类）。
 三个例子（基于前面 Quote/Bulk_quote）

 Quote *pq = new Bulk_quote("123",50,10,0.2);
 // pq静态类型：Quote*；动态类型：Bulk_quote*
 
 Quote &rq = Bulk_quote("456", 40, 5, 0.1);
 // rq静态类型：Quote&；动态类型：Bulk_quote
 
 Quote *p = &Bulk_quote("789",30,20,0.15);
 // p静态类型：Quote*；动态类型：Bulk_quote*
 */
