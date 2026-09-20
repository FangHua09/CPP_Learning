/*
题目描述
使用普通迭代器逆序打印一个 vector。
知识点
普通正向迭代器默认从头部向尾部遍历，逆序需要从尾后迭代器end()开始，先自减再访问元素。
end()指向尾元素的下一个位置，不能直接解引用，必须先--移动到尾元素。
循环终止条件是迭代器等于begin()，注意边界控制，避免越界。
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
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    // 普通正向迭代器逆序遍历
    auto it = vec.end();
    while(--it != vec.begin() - 1) {
        cout << *it << ' ';
    }
    return 0;
}
