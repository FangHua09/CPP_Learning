/*
修改前一题的程序，使其只打印不重复的元素。程序应使用unique_copy。
知识点
unique_copy(beg, end, dest)：将区间元素复制到目标位置，相邻重复元素只保留第一个，因此源序列必须先排序。
输出目标可以直接使用ostream_iterator，无需额外容器存储去重结果。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof); // 从标准输入读取整数

    sort(vec.begin(), vec.end()); // 排序

    // 输出到标准输出，每个元素后跟空格
    ostream_iterator<int> out_iter(cout, " ");
    unique_copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
    return 0;
}