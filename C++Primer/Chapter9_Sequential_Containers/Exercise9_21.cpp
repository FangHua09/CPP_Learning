/*
题目：如果我们将第 308 页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作。
原逻辑（list 版本）：
auto iter = lst.begin();
while(cin >> word)
{
    iter = lst.insert(iter, word);
}

insert：在迭代器iter之前插入元素，返回指向新插入元素的迭代器。
list 插入不会使迭代器失效，循环正常。


工作情况
vector::insert同样在迭代器之前插入，返回新元素迭代器；
vector 插入会导致内存重新分配，会使原有迭代器失效；但是代码里每次都接收insert返回的新迭代器iter，iter始终保持有效；
功能上可以运行，每次新元素插在容器头部；

性能很差：vector 头部插入，每一次插入都要移动后面全部元素；大量插入效率极低。
总结：语法可以正确运行，逻辑结果正确，但性能很差。

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

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> lst;
    string line;
    auto iter = lst.begin();
    while (cin >> line)
    {
        iter = lst.insert(iter, line); // 类似头插法
    }

    for (auto &&i : lst)
    {
        cout << i << ' ';
    }
//     /*
// ont two three
// ^Z
// three two ont
//     */



    return 0;
}
