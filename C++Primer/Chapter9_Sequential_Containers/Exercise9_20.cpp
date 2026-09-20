/*
题目：编写程序，从一个list<int>拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。
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
    std::list<int> lst{1,2,3,4,5,6,7,8};
    std::deque<int> even_deque;  //偶数
    std::deque<int> odd_deque;   //奇数

    for (auto &&i : lst)
    {
        if(i % 2 == 0) even_deque.push_back(i);
        else odd_deque.push_back(i);
    }

    std::cout << "偶数：";
    for(auto x : even_deque) std::cout << x << " ";
    std::cout << "\n奇数：";
    for(auto x : odd_deque) std::cout << x << " ";
    
    return 0;
}
