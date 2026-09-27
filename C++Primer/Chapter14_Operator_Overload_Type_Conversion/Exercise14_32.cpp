/*
 *定义一个类，内部保存指向 StrBlobPtr 的指针，重载箭头运算符 ->
 */

#include <memory>
#include <vector>
#include <string>
class StrBlob;
class StrBlobPtr
{
private:
    StrBlob *ptr;

public:
    StrBlobPtr(StrBlob *ptr) : ptr(ptr) {}
    // 重载*
    StrBlob &operator*() const
    {
        return (*ptr);
    }
    // 重载->
    StrBlob *operator->() const
    {
        return &(this->operator*());
    }
};

class StrBlobPtrPtr
{
private:
    StrBlobPtr *ptr;

public:
    StrBlobPtrPtr(StrBlobPtr *ptr) : ptr(ptr) {}
    // 重载*
    StrBlobPtr &operator*() const
    {
        return *ptr;
    }
    // 重载->
    StrBlobPtr *operator->() const
    {
        return &(this->operator*());
    }
};

/*
StrBlob blob{"hello", "world"};
StrBlobPtr iter = blob.begin();
StrBlobPtrPtr p(&iter);
p->deref(); // 等价于 p.operator->()->deref();

原理：p->deref() 执行流程：
调用StrBlobPtrPtr::operator->() 返回StrBlobPtr*
编译器继续对返回的原生指针调用->，调用StrBlobPtr成员函数deref()
补充：注意内存管理，上面示例使用裸指针；实际工程可以改用unique_ptr<StrBlobPtr>。

C++ Primer 原版 StrBlobPtr 不是存 StrBlob*，而是：
weak_ptr<vector<string>> wptr;
size_t curr;
它是迭代器，指向容器内某个字符串，不是指向 StrBlob 本身。
*/