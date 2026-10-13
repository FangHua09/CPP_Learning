/*
 *前置知识：文本查询 Query 类体系
 Query(s)：创建WordQuery（单词查询）对象，包装到 Query 句柄类
 ~Query：一元取反运算符，生成NotQuery
 &：查询与运算，生成AndQuery
 |：查询或运算，生成OrQuery
 运算符优先级：一元～> & > |
 
 
 (a) Query(s1) | Query(s2) & ~Query(s3);
 优先级：~最高，然后&，最后|等价括号写法：
 plaintext
 Query(s1) | ( Query(s2) & (~Query(s3)) );
 对象创建顺序：
 Query(s1) → WordQuery
 Query(s2) → WordQuery
 Query(s3) → WordQuery
 ~Query(s3) → NotQuery（包装 s3 的 WordQuery）
 Query(s2) & NotQuery → AndQuery（s2 和 NotQuery (s3)）
 Query(s1) | AndQuery → OrQuery（s1 和上面的 AndQuery）
 ✅ 最终创建对象：WordQuery(s1)、WordQuery(s2)、WordQuery(s3)、NotQuery、AndQuery、OrQuery
 
 
 (b) Query(s1) | (Query(s2) & ~Query(s3));
 括号强制优先计算括号内部，表达式结构和 (a) 完全一样！等价：
 plaintext
 Query(s1) | ( Query(s2) & (~Query(s3)) );
 对象创建：和 (a) 完全相同：WordQuery(s1), WordQuery(s2), WordQuery(s3), NotQuery, AndQuery, OrQuery
 对比 (a)：因为&优先级本来就高于|，加括号不改变运算顺序，最终生成的对象完全一样。
 
 
 (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
 优先级：&高于|等价括号：
 plaintext
 ( Query(s1) & Query(s2) ) | ( Query(s3) & Query(s4) );
 对象创建：
 Query(s1) WordQuery
 Query(s2) WordQuery
 Query(s1) & Query(s2) → AndQuery1
 Query(s3) WordQuery
 Query(s4) WordQuery
 Query(s3) & Query(s4) → AndQuery2
 AndQuery1 | AndQuery2 → OrQuery
 ✅ 创建对象：WordQuery(s1),WordQuery(s2),WordQuery(s3),WordQuery(s4)，两个AndQuery，一个顶层OrQuery
 */

