/*
 *原题：派生类（AndQuery/OrQuery/NotQuery）成员如果保存shared_ptr<Query_base>而不是Query对象，类需要怎么改？
 原来设计：BinaryQuery 里面存Query lhs, rhs（句柄类）。
 修改方案：
 AndQuery、OrQuery、NotQuery 不再保存 Query 对象，改为保存shared_ptr<Query_base> lhs; shared_ptr<Query_base> rhs;
 BinaryQuery 构造函数接收shared_ptr<Query_base>，不再接收 Query 对象；
 rep()成员不能调用lhs.rep()，必须写成lhs->rep()；
 重载运算符& | ~内部传入shared_ptr<Query_base>而不是 Query；
 好处：减少 Query 临时对象的创建；代价：代码要手动管理 shared_ptr，不能依靠 Query 句柄封装。
 简单总结：去掉 Query 句柄包装，直接持有底层基类智能指针，所有obj.rep()改为obj->rep()。
 */
