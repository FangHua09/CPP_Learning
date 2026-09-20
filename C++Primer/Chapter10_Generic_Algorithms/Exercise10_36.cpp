/*
题目描述
使用 find 在一个 int 的 list 中查找最后一个值为 0 的元素。
知识点
find 是正向查找，返回第一个匹配元素的迭代器；要找最后一个匹配元素，可以配合反向迭代器实现。
对反向迭代器调用find，找到的第一个匹配元素，对应原序列中最后一个匹配元素。
反向迭代器的base()成员函数可以转回对应的正向迭代器，指向原序列中该反向迭代器对应的下一个位置，需要回退一位得到目标元素。
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
    list<int> lst = {0, 1, 0, 2, 3, 0, 4, 5};
    auto last_zero_riter = find(lst.rbegin(), lst.rend(), 0);

    // 返回正向迭代器  // 转回正向迭代器，base()指向目标元素的下一位，需要回退
    auto last_zero_iter = last_zero_riter.base();
    last_zero_iter--;

    if (last_zero_iter != lst.end())
        cout << "最后一个0的值：" << *last_zero_iter << endl;
    else
        cout << "未找到0" << endl;
    return 0;
}
