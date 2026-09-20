/*
题目描述：当我们将一个 StrBlob 赋值给另一个 StrBlob 时，会发生什么？赋值 StrBlobPtr 呢？
知识点：shared_ptr 的拷贝、StrBlob 与 StrBlobPtr 的成员构成，拷贝赋值行为
解答
StrBlob：内部核心成员是shared_ptr<vector<string>>。
执行sb1 = sb2时，调用合成拷贝赋值：
左侧对象 sb1 原来的 shared_ptr 引用计数减 1；
把 sb2 内 shared_ptr 拷贝给 sb1，这个 shared_ptr 引用计数 + 1；
两个 StrBlob 的 shared_ptr 现在指向同一个 vector，共享底层数据。
StrBlobPtr：成员包含weak_ptr<vector<string>>和size_t索引。
sbp1 = sbp2，合成拷贝赋值会拷贝 weak_ptr 和索引：
两个 StrBlobPtr 保存同一个底层 vector 的弱引用，并且保存相同行号；weak_ptr 拷贝不会增加 shared_ptr 引用计数。
*/
