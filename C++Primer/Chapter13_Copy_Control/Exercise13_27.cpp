/*
练习 13.27：定义引用计数版本的 HasPtr
引用计数版本（行为像指针）：多个 HasPtr 对象共享同一个堆上 string；额外维护一个引用计数，
记录当前有多少对象共享该 string。当引用计数减到 0 时，才释放 string 和计数本身。
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

class HasPtr {
public:
    // 构造函数
    HasPtr(const string& s = string()): ps(new string(s)), use(new size_t(1)), i(1){} 

    // 拷贝构造函数
    HasPtr(const HasPtr& orgi):ps(orgi.ps), i(orgi.i), use(orgi.use){
        ++*use;
    }

    // 拷贝赋值
    HasPtr& operator= (const HasPtr& rhs){
        // 先递增右侧引用计数， 递减左侧引用计数， 适时删除
        ++*rhs.use;
        if(--*use == 0){
            delete ps;
            delete use;
        }
        // 再逐个赋值
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        // 返回左侧对象引用
        return *this;
    }

    // 析构函数
    ~HasPtr(){
        if(--*use == 0){
            delete use;
            delete ps;
        }
    }

private:
    string *ps;
    int i;
    size_t *use; // 引用计数，记录共享该string的对象数量
};
