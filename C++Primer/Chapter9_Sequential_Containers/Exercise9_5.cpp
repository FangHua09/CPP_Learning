/*
题目描述：重写上一题的函数，返回一个迭代器指向找到的元素。
注意，程序必须处理未找到给定值的情况。
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

vector<int>::iterator findVal(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while (beg != end)
    {
        if (val == *beg)
            return beg;
        beg++;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{11, 22, 33, 44};
    auto it1 = findVal(vec.begin(), vec.end(), 22);
    if (it1 != vec.end())
        std::cout << *it1 << std::endl;

    auto it2 = findVal(vec.begin(), vec.end(), 99);
    if (it2 == vec.end())
        std::cout << "not found" << std::endl;

    /*
    22
not found
    */
    return 0;
}
