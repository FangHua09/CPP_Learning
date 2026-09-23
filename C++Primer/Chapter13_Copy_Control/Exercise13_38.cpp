/*
题目：为什么 Message 赋值运算符没有使用拷贝并交换（copy and swap）写法？

核心原因：Message 的赋值运算符需要维护双向关联。
copy-and-swap 的思路：先构造 rhs 副本，swap，旧对象随临时变量销毁。

如果用 copy-and-swap 实现 Message::operator=：
拷贝出的临时 Message 构造时，会调用 add_to_Folders，向所有 Folder 插入临时 Message 指针；
接着 swap 交换；然后临时对象析构，会调用 remove_from_Folders，把临时 Message 从 Folder 删掉。
但是我们最终想要的是：把 Folder 里旧的 this 指针移除，替换成新 rhs 消息内容。
copy-and-swap 会导致 Folder 里的消息指针反复添加、删除，而且 Folder 保存的指针仍然是原来 this 的地址！
Message 的 this 指针本身不会变，copy-and-swap 交换的是成员，无法替换 Folder 中保存的 Message 指针。

一句话总结：
copy-and-swap 适合对象独立，没有外部反向指针的场景（HasPtr）。
Message 和 Folder 互相保存对方指针，Folder 里存着 Message*。就算交换 Message 内部成员，Folder 保存的 Message 指针地址不变，copy-and-swap 在这里没有收益，还会带来额外的双向关联维护开销。
*/
