/*
 *练习 15.38 判断合法性
 cpp
 BinaryQuery a = Query("fiery") & Query("bird");
 AndQuery b = Query("fiery") & Query("bird");
 OrQuery c = Query("fiery") & Query("bird");
 全部不合法
 理由：
 Query("fiery") & Query("bird")返回的类型是Query（句柄类），不是 BinaryQuery/AndQuery/OrQuery。
 Query 是句柄，保存 shared_ptr，不是继承关系，不存在隐式转换到 BinaryQuery/AndQuery/OrQuery。
 BinaryQuery 是抽象基类（拥有纯虚 rep，或者继承自 Query_base 纯虚），本身不能实例化，连定义BinaryQuery a;都不允许。
 一句话：Query 是独立句柄，不是派生类；不能把 Query 对象赋值给 BinaryQuery/AndQuery/OrQuery 变量。
 */
