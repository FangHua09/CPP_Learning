/*
练习 13.33
题目：为什么 Message 的成员 save 和 remove 的参数是一个 Folder&？为什么不定义为 Folder 或者 const Folder&？

save：把当前 Message 加入 Folder 的消息集合；remove：把当前 Message 从 Folder 的消息集合移除。
不能是Folder（值传递）：值传递会拷贝一个全新的临时 Folder 对象。我们想要修改原始 Folder 对象内部的 set，拷贝出来的副本和原 Folder 无关，操作副本没有意义。
不能是const Folder&：save/remove 要修改 Folder 内部保存 Message 的 set 容器，const Folder&代表不能修改 Folder 对象，编译报错。
所以只能用Folder&：普通引用，绑定到原 Folder 对象，可以修改 Folder 内部的消息集合，且不发生对象拷贝。
*/
