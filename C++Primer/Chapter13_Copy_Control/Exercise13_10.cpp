/*
问题：当一个 StrBlob 对象销毁时会发生什么？一个 StrBlobPtr 对象销毁时呢？
StrBlob 核心成员：shared_ptr<vector<string>> 
dataStrBlobPtr 核心成员：weak_ptr<vector<string>> wptr; size_t curr;

StrBlob 对象销毁
调用合成析构函数。销毁成员data，shared_ptr的析构函数会递减引用计数。
如果引用计数变为 0：释放底层vector<string>；
如果引用计数 > 0：vector 保留，其他 StrBlob 对象还在共享这份数据。

StrBlobPtr 对象销毁
调用合成析构函数。销毁成员wptr（weak_ptr 析构）与curr（内置 size_t 直接销毁）。
weak_ptr析构不改变 shared_ptr 的引用计数，仅销毁自身弱引用。底层 vector 是否释放，仍然由 shared_ptr 的引用计数决定。
*/
