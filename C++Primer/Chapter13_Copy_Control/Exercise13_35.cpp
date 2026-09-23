/*
题目：如果 Message 使用合成拷贝控制成员，会发生什么？
合成版本只会做逐成员拷贝：
合成拷贝构造：拷贝contents、拷贝folders（set<Folder*>，只复制指针值）。
但是！不会调用 add_to_Folders，新 Message 不会添加到任何 Folder 的消息集合。Folder 里只有旧 Message 指针，没有新 Message。
合成析构：只会销毁 contents 和 folders，不会调用 remove_from_Folders。Folder 中还保留着已经销毁的 Message 悬垂指针！
合成拷贝赋值：逐成员赋值，同样不会更新 Folder 里的消息集合。
后果：Folder 和 Message 双向关联被破坏，出现悬垂指针，程序崩溃 / 逻辑错误。
一句话：合成拷贝控制只复制成员变量，不会维护 Message 和 Folder 之间双向指针关系。
*/
