/*
题目：为 Message 添加成员，向 folders 添加 / 删除给定 Folder*，类似 Folder 的 addMsg、remMsg
在 Message 类 public 中增加两个成员：

// Message类内添加
void addFld(Folder *f) {
    folders.insert(f);
}
void remFld(Folder *f) {
    folders.erase(f);
}
用途：Folder 操作时，用来更新 Message 内部的 folders 集合，和 Folder::addMsg /remMsg 成对。
*/
