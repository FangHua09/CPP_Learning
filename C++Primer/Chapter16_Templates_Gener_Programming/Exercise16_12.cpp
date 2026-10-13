/*
 *练习 16.12：编写 Blob 和 BlobPtr 模板，补充 const 成员
 核心要点：
 Blob<T>底层用shared_ptr<vector<T>>管理数组；
 增加cbegin()、cend()返回 const 版本迭代器；
 BlobPtr<T>、ConstBlobPtr<T>两套迭代器，Blob提供 const 成员，供 const 对象调用。
 思路和教材原版 Blob 一致，补充const版本的 begin/end，以及ConstBlobPtr。
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

template <typename T>
class Blob
{
    using size_type = typename vector<T>::size_type;
    // typedef typename vector<T>::size_type size_type; 简单的typedef不支持泛型重定义
    // 构造函数
    Blob();
    Blob(initializer_list<T> il);
    // Blob 中元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const T &t) { data->push_back(t); }
    void pop_back();
    // 移动添加
    void push_back(T &&t) { data->push_back(move(t)); } // 记得使用move
    // 元素访问
    T &back();
    T &operator[](size_type sz);

    // begin end成员
    BlobPtr<T> begin();
    BlobPtr<T> end();
    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

private:
    shared_ptr<vector<T>> data;
    void check(size_type sz, const string &msg) const;
};
