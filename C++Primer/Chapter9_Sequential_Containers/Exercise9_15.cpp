/*
题目：编写程序，判定两个vector<int>是否相等。
分析：vector重载了==运算符，会逐元素比较，长度不同直接不相等。
> ：`==`要求两个 vector**类型完全相同**，大小相等，且每一个对应元素都相等。
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
    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{1, 2, 3, 4};
    std::vector<int> v3{1, 2, 3};

    if (v1 == v2)
        std::cout << "v1 与 v2 相等\n";
    else
        std::cout << "v1 与 v2 不相等\n";

    if (v1 == v3)
        std::cout << "v1 与 v3 相等\n";
    else
        std::cout << "v1 与 v3 不相等\n";
    return 0;
}
