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
    // 移动构造
    Message(Message &&);
    // 移动赋值
    Message &operator=(Message &&);

    // save, remove
    void save(Folder &);
    void remove(Folder &);

private:
    string contents;
    set<Folder *> folders;
    // 拷贝构造 拷贝赋值 析构所用到的工具函数
    // 将folders里所有文件夹中添加自己的指针
    void add_to_folders(const Message &orgi); // 拷贝构造 + 拷贝赋值

    // 将folders里所有文件夹中删除自己
    void remove_from_folders(); // 析构 + 拷贝赋值

    // 移动构造 移动赋值 所用到的工具函数
    void move_folders(Message*);
};

class Folder
{
public:
    // 拷贝构造函数
    Folder(const Folder &orgi);

    // 拷贝赋值运算符
    Folder &operator=(const Folder &rhs);

    // 析构函数
    ~Folder();

    // 将给定的message指针添加到自己的messages中
    void addMsg(Message *);

    // 将给定的message指针从自己的messages中删除
    void remMsg(Message *);

private:
    set<Message *> messages;
    // 工具函数
    // 将messages里所有文件都添加自己的指针
    void add_to_messages(const Folder &); // 拷贝构造 + 拷贝赋值

    // 将message里所有文件都删除自己的指针
    void remove_from_messages(); // 析构 + 拷贝赋值
};

// 将folders里所有文件夹中添加自己的指针
void Message::add_to_folders(const Message &orgi)
{
    // 将本this新message的指针添加到orgi.folders里,剩下的交给列表初始化来拷贝
    for (auto &&f : orgi.folders)
    {
        f->addMsg(this);
    }
}

// 将folders里所有文件夹中删除自己
void Message::remove_from_folders()
{
    for (auto &&f : folders)
    {
        f->remMsg(this);
    }
}

void Message::move_folders(Message* m){
    // 将m从m的folders里移除，添加this
    for (auto &&f : m->folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    // 确保销毁m是无害的
    m->folders.clear();
}

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
Message &Message::operator=(const Message &rhs)
{
    // 把左侧运算对象的folders中把自己删除，在右侧对象的folders中新增自己
    // 先处理自赋值
    if (this == &rhs)
        return *this; // 增加自赋值判断
    remove_from_folders();
    this->contents = rhs.contents;
    this->folders = rhs.folders;
    this->add_to_folders(rhs);
    return *this;
}

// 移动构造
Message::Message(Message &&orig)
{
    contents = std::move(contents);
    move_folders(&orig); // 因为folders需要特殊移动 写成函数
}
// 移动赋值
Message &Message::operator=(Message &&rhs)
{
    if(this == &rhs) return *this;
    remove_from_folders(); // 特殊销毁左运算对象的holders
    contents = std::move(contents);
    move_folders(&rhs); // 因为folders需要特殊移动 写成函数，里面处理了置于可销毁状态
    return *this;
}

// save，将给定文件夹保存到自己的folders
void Message::save(Folder &f)
{
    folders.insert(&f);
    // 同时在给定文件夹f的messages中添加自己的指针
    f.addMsg(this);
}

// remove，将给定的文件夹从自己的folders中删除
void Message::remove(Folder &f)
{
    folders.erase(&f);
    // 同时在给定文件夹f的messages中删除自己的指针
    f.remMsg(this);
}

// 将给定Message指针添加到自己的messages中
void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

// 将给定的message指针从自己的messages中删除
void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

// 从给定的orgi的messages中指向的文件夹保存自己的指针
void Folder::add_to_messages(const Folder &orgi)
{
    for (auto &&m : orgi.messages)
    {
        m->save(*this);
    }
}

// 从当前的messages中删除自己的指针
void Folder::remove_from_messages()
{
    for (auto &&m : messages)
    {
        m->remove(*this);
    }
}

// 拷贝构造
Folder::Folder(const Folder &orgi) : messages(orgi.messages)
{
    // 将自己的指针添加到右侧运算对象的messages里指向的每个message添加左侧对象自己的指针
    add_to_messages(orgi);
}

// 拷贝赋值
Folder &Folder::operator=(const Folder &rhs)
{
    if (this == &rhs)
        return *this; // 增加自赋值判断
    remove_from_messages();
    this->messages = rhs.messages;
    add_to_messages(rhs);
    return *this;
}

// 析构
Folder::~Folder()
{
    remove_from_messages();
}
