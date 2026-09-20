/*
题目：解释拷贝、赋值、销毁 TextQuery 和 QueryResult 对象会发生什么。
回顾类成员：
TextQuery：
strBlob file; 
map<string,shared_ptr<set<line_no>>> wm;

QueryResult：
string sought; 
shared_ptr<set<line_no>> lines; 
strBlob file;

strBlob内部是shared_ptr<vector<string>>。

拷贝（拷贝构造）
TextQuery 拷贝：合成拷贝构造，逐成员拷贝。strBlob拷贝会复制内部shared_ptr，引用计数 + 1；map 拷贝：拷贝 map 里每一对string和shared_ptr<set>，每个 shared_ptr 引用计数 + 1。拷贝后两个 TextQuery 共享底层 vector、共享行号集合。
QueryResult 拷贝：合成拷贝构造，拷贝sought字符串；拷贝lines这个 shared_ptr，行号集合引用计数 + 1；拷贝strBlob成员，底层文本 vector 引用计数 + 1。拷贝后的 QueryResult 共享同一文本和同一行号集合。
赋值（拷贝赋值）
合成拷贝赋值，逐成员赋值。赋值时，左侧对象原来的成员销毁：shared_ptr引用计数递减；如果引用计数变为 0，则释放对应的内存。然后把右侧对象成员拷贝过来，对应 shared_ptr 引用计数 + 1。
销毁（析构）
调用合成析构函数，依次销毁所有成员。成员里的shared_ptr执行析构，引用计数减 1。当引用计数降到 0，释放底层 vector 或者 set 集合。
一句话总结：两个类都使用 shared_ptr 管理资源，合成拷贝控制只是共享底层资源，增加 / 减少引用计数，不会深拷贝整个文件和行号集合。
*/
