/*
给定一个包含 10 个元素的 vector，将位置 3 到 7 之间的元素按逆序拷贝到一个 list 中。
知识点
位置从 0 开始计数，位置 3 到 7 对应索引 3、4、5、6、7 共 5 个元素，左闭右开区间为[begin()+3, begin()+8)。
reverse_copy(beg, end, dest)：将正向区间[beg,end)的元素逆序拷贝到目标迭代器 dest。
也可以通过反向迭代器区间直接拷贝，效果等价。
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
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9}; // 10个元素，索引0-9 // 逆序打印 3 - 7
    list<int> lst;

    reverse_copy(vec.begin() + 3, vec.begin() + 8, inserter(lst, lst.begin()));
    /*
    核心原因：空 list 不能直接用 lst.begin() 作为拷贝目标。
    reverse_copy 是覆盖式写入：它假设目标位置已经存在元素，直接覆盖它们的值。
    你的 lst 初始为空，lst.begin() 不指向任何有效元素，直接写入属于越界未定义行为，不会自动向 list 中添加元素，所以 lst 从头到尾都是空的，遍历自然没有输出。
    ✅ 解决方法：使用插入迭代器 back_inserter(lst)，它会在写入时自动调用 push_back 向容器尾部添加元素。
    */

    // 提供一种反向迭代器的实现
    // copy(vec.rbegin() + 2, vec.rbegin() + 7, inserter(lst, lst.begin()));

    for (auto val : lst)
        cout << val << " ";
    cout << endl;
    return 0;
}
