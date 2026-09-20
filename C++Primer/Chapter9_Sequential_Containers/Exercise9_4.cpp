/*
题目描述：编写函数，接受一对指向vector<int>的迭代器和一个int值。
在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
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

bool findVal(vector<int>::iterator beg, vector<int>::iterator end, int val){
    while(beg != end) {
        if(val == *beg) return true;
        beg++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{10,20,30,40,50};
    std::cout << std::boolalpha;
    std::cout << findVal(vec.begin(), vec.end(), 30) << std::endl;  //true
    std::cout << findVal(vec.begin(), vec.end(), 99) << std::endl; // false
    return 0;
}
