/*
 *(a) 所有执行的构造函数
 表达式：Query("fiery") & Query("bird") | Query("wind")

 Query("fiery")：构造WordQuery，然后用shared_ptr<Query_base>构造Query 句柄
 Query("bird")：构造WordQuery，构造 Query 句柄
 &运算符：创建AndQuery（接收两个shared_ptr<Query_base>），再构造 Query 句柄包装 AndQuery
 Query("wind")：构造WordQuery，构造 Query 句柄
 |运算符：创建OrQuery（接收 AndQuery 的 shared_ptr 和 WordQuery (wind) 的 shared_ptr），构造 Query 句柄包装 OrQuery
 构造清单：
 WordQuery ("fiery"), Query (shared_ptr),
 WordQuery ("bird"), Query (shared_ptr),
 AndQuery, Query (shared_ptr),
 WordQuery ("wind"), Query (shared_ptr),
 OrQuery, Query (shared_ptr)


 (b) cout << q 调用的 rep()
 cout << q 调用 Query 的operator<<，内部调用q.rep()，虚调用链：
 顶层是 OrQuery → OrQuery::rep()
 OrQuery 内部会递归调用左操作数 AndQuery 的AndQuery::rep()，AndQuery 内部递归调用两个 WordQuery 的WordQuery::rep()；
 OrQuery 再调用右操作数 WordQuery ("wind") 的WordQuery::rep()
 输出形式：(fiery & bird) | wind


 (c) q.eval()调用的 eval
 q.eval()虚调用顶层OrQuery::eval()
 OrQuery 先调用左子表达式AndQuery::eval()
 AndQuery 调用 WordQuery ("fiery").eval ()，得到 fiery 的行号集合
 AndQuery 调用 WordQuery ("bird").eval ()，得到 bird 的行号集合
 AndQuery 求两个集合的交集，返回交集集合
 OrQuery 调用右子表达式 WordQuery ("wind").eval ()，得到 wind 行号集合
 OrQuery 对交集集合、wind 集合求并集，返回最终结果集合
 */
