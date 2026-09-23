/*
题目：编写本节描述的 Message 类
知识点
Message：保存文本contents，保存所属 Folder 指针集合folders
save (Folder& f)：将 this（当前 Message）加入 f 的消息列表
remove (Folder& f)：将 this 从 f 的消息列表移除
拷贝构造：拷贝 contents，并且把新 Message 加入所有原 Message 所属的 Folder
析构函数：从所有所属 Folder 中删除本 Message
拷贝赋值：先移除旧 folders 里的 this，拷贝内容，再加入新 folders
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <numeric>
#include <bitset>
#include <climits>
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

class Folder;
class Message
{
    friend class Folder;

public:
    Message(const string &s = "") : contents(s) {}

    // 拷贝构造
    Message(const Message &);
    // 拷贝赋值
    Message &operator=(const Message &);
    // 析构
    ~Message();

    // save, remove
    void save(Folder &);
    void remove(Folder &);

private:
    string contents;
    set<Folder *> folders;
    // 拷贝构造 拷贝赋值 析构所用到的工具函数

    // 将folders里所有文件夹中添加自己的指针
    void add_to_folders(const Message &orgi)
    {
        // 将本this新message的指针添加到orgi.folders里,剩下的交给列表初始化来拷贝
        for (auto &&f : orgi.folders)
        {
            f->addMsg(this);
        }
    }

    // 将folders里所有文件夹中删除自己
    void remove_from_folders()
    {
        // 将本成员从folders中所有指向的文件夹中删去自己的指针。与上面的可以抽取成一个方法
        for (auto &&f : folders)
        {
            f->remMsg(this);
        }
    }
};

class Folder
{
public:
    // 将给定的message指针添加到自己的messages中
    void addMsg(Message *);
    // 将给定的message指针从自己的messages中删除
    void remMsg(Message *);

private:
    set<Message *> messages;
};

// 类外实现Message
// 拷贝构造
Message::Message(const Message &orgi) : contents(orgi.contents), folders(orgi.folders)
{
    // 将本this新message的指针添加到orgi.folders里,剩下的交给列表初始化来拷贝
    add_to_folders(orgi);
}

// 析构
Message::~Message()
{
    // 将本成员从folders中所有指向的文件夹中删去。与上面的可以抽取成一个方法
    remove_from_folders();
}

// 拷贝赋值
Message& Message::operator=(const Message& rhs){
    // 把左侧运算对象的folders中把自己删除，在右侧对象的folders中新增自己
    // 先处理自赋值
    remove_from_folders();
    this->contents = rhs.contents;
    this->folders = rhs.folders;
    this->add_to_folders(rhs);
    return *this;
}

// save，将给定文件夹保存到自己的folders
void Message::save(Folder& f){
    folders.insert(&f);
    // 同时在给定文件夹f的messages中添加自己的指针
    f.addMsg(this);
}

// remove，将给定的文件夹从自己的folders中删除
void Message::remove(Folder& f){
    folders.erase(&f);
    // 同时在给定文件夹f的messages中删除自己的指针
    f.remMsg(this);
}