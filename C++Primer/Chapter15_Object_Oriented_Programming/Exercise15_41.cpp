/*
 *
核心思路
原版用 shared_ptr<Query_base>（智能指针，自动管理引用计数、自动释放内存）。
改成裸指针（内置指针）：
Query 内部成员从 shared_ptr<Query_base> q; → Query_base* q;
所有 make_shared / shared_ptr<Query_base>(new XXX) 全部改成直接 new，返回裸指针
必须手动释放内存，防止内存泄漏；Query 析构函数里 delete q;
注意：Query 的拷贝构造 / 拷贝赋值会带来浅拷贝双重释放问题！最简单方案：禁用拷贝，只允许移动（C++11），或者实现深拷贝（这个继承体系深拷贝麻烦，一般禁用拷贝）。
重点：Query_base 的虚析构函数必须保留！否则 delete 基类指针不会调用子类析构，内存泄漏。
 */
/*
 * 练习15.39：把Query内部的shared_ptr<Query_base>改为内置裸指针
 * QueryResult / TextQuery 仍然使用shared_ptr，仅修改查询表达式框架
 * 
 * 
 * class Query_base {
    // ...
    virtual Query_base* clone() const = 0; // 虚克隆
};
class Query {
private:
    Query_base* qb; // 裸指针
public:
    ~Query() { delete qb; } // 析构释放
    // 必须自定义拷贝，深拷贝
    Query(const Query& rhs) : qb(rhs.qb->clone()) {}
    Query& operator=(const Query& rhs) {
        auto newp = rhs.qb->clone();
        delete qb;
        qb = newp;
        return *this;
    }
    // 移动构造可以转移指针
    Query(Query&& rhs) noexcept { qb = rhs.qb; rhs.qb = nullptr; }
};
 */
