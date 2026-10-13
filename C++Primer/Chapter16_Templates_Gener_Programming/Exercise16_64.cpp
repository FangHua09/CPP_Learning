/*
 *练习 16.64：为上面模板写特例化，处理 vector<const char*>
 普通模板直接比较const char*是指针地址比较，不是字符串内容比较，所以要全特例化。
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
size_t countOccur(const vector<T> &vec, const T &val)
{
    size_t acount = 0;
    for (auto &&i : vec)
    {
        if (i == val)
            ++acount;
    }
    return acount;
}

// 特例化版本
template <>
size_t countOccur(const vector<const char *> &vec, const char *const &val)
{
    size_t acount = 0;
    for (auto &&i : vec)
    {
        if (strcmp(i, val) == 0)
            ++acount;
    }
    return acount;
}

int main()
{
    vector<const char *> vc{"hi", "hello", "hi"};
    cout << countOccur(vc, static_cast<const char *>("hi")) << endl; // 输出2，按字符串内容比较
    return 0;
}
/*
第一个实参 vc：vector<const char*> → 推导出 T = const char*
第二个实参 "hi"：类型是 const char[3]，数组试图转 const T&，也就是 const char* const &
问题：全特化写的位置，模板推导优先，全特化不会参与模板参数推导！
👉 全特化只是主模板的一个特例版本；模板参数 T 仍然是从函数实参先推导出来，推导失败的话，根本不会去看你的全特化。
拆解你的调用
countOccur(vc, "hi");
第一个参数：vector<const char*>& → 告诉编译器 T = const char *
第二个参数："hi" 是 const char[3]，要绑定到 const T& = const char* const &
字符串字面量数组可以隐式转为 const char*，但是：
模板参数推导时，数组不会自动转指针给引用形参！
const T& val，当 T 推导为const char*，val类型是 const char* const &
const char[3] 不能直接绑定到这个引用，数组到指针转换不会发生在模板实参推导的引用场景，于是推导冲突。
重点：全特化不能救推导失败。必须先推导成功，才会选择使用全特化版本。
方案 1：调用时手动把字面量转 const char*（最简单）
countOccur(vc, static_cast<const char*>("hi"));
*/