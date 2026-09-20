/*
问：拷贝 StrBlob，拷贝 StrBlobPtr 会发生什么？
StrBlob内部保存shared_ptr，拷贝 StrBlob 时，shared_ptr 的引用计数 + 1，两个 StrBlob 共享底层的 vector，是浅拷贝。
StrBlobPtr是 StrBlob 的指针类，内部也持有weak_ptr。拷贝 StrBlobPtr 时，weak_ptr 拷贝，底层 vector 的引用计数不变；两个 StrBlobPtr 指向同一个 StrBlob 的 vector。
一句话总结：
拷贝StrBlob：shared_ptr引用计数递增，共享 vector；
拷贝StrBlobPtr：weak_ptr拷贝，不改变 shared_ptr 计数，共享同一个 vector。
*/
