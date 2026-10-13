/*
 *练习 16.58：给 StrVec、Vec 添加 emplace_back
 emplace_back 是可变参数成员模板，使用万能引用 + 完美转发，在容器已分配的原始内存里就地构造对象（placement new），而不是先创建临时对象再拷贝 / 移动。
 StrVec 的 emplace_back
 */
#include <memory>
#include <string>
using namespace std;

class StrVec
{
public:
    // 可变参数成员模板，万能引用参数包
    template <typename... Args>
    void emplace_back(Args &&...args);

private:
    string *elements;
    string *first_free;
    string *finish;
    allocator<string> alloc;
    bool has_space() const { return finish != first_free; }
    void reallocate() { /* 扩容逻辑，教材原版 */ }
};
template <typename... Args>
void StrVec::emplace_back(Args &&...args)
{
    if (!has_space())
    {
        reallocate();
    }
    alloc.construct(first_free++, forward<Args> args...);
}

template <typename T>
class Vec
{
public:
    template <typename... Args>
    void emplace_back(Args &&...args);

private:
    T *elements;
    T *first_free;
    T *finish;
    allocator<T> alloc;
    bool has_space() const { return finish != first_free; }
    void reallocate() { /* 扩容 */ }
};

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args &&...args){
    if(!has_space()){
        reallocate();
    }
    alloc.construct(first_free++, forward<Args>(args)...);
}