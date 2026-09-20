/*
题目描述
除了unique之外，标准库还有unique_copy，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写程序，使用unique_copy将一个 vector 中不重复元素拷贝到一个初始为空的 list 中。

知识点
unique_copy(beg, end, dest)：把区间[beg,end)元素复制到dest起始位置；相邻重复元素只保留一份。
unique_copy只去除相邻重复元素，因此源序列必须先排序。
目标容器是空的，必须搭配插入迭代器（back_inserter），不能直接传容器的 begin 迭代器。
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    list<int> lst; // 初始为空list

    // 去重之前需要先排序
    sort(vec.begin(), vec.end());

    // 因为lst为空。所以需要借助插入迭代器
    // 可以用inserter和back_inserter
    // unique_copy(vec.begin(), vec.end(), insert_iterator(lst, lst.begin()));
    unique_copy(vec.begin(), vec.end(), back_insert_iterator(lst));

    // 打印list
    for (auto num : lst)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
