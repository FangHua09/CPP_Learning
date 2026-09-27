/*
 *练习 14.37：相等判断仿函数，搭配replace_if替换序列中所有等于给定值的元素
 replace_if(开始迭代器,结束迭代器,谓词,新值)；谓词是仿函数，判断元素是否等于目标值。
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

class EqualValue
{
private:
    int val;

public:
    EqualValue(int val) : val(val) {}
    bool operator()(int v) const
    {
        return v == val;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> vec{1, 2, 3, 2, 4, 2, 5};
    // 将所有等于2的元素替换成99....2传入到成员中
    replace_if(vec.begin(), vec.end(), EqualValue(2), 99);

    for (auto num : vec)
        std::cout << num << " ";
    return 0;
}
