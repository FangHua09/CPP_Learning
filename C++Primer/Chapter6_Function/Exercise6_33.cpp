// 题目描述：编写一个递归函数，输出 vector 对象的内容。
#include <iostream>
#include <vector>
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

void print_vec(vector<int>::const_iterator beg, vector<int>::const_iterator end){
    if (beg == end) return;
    cout << *beg << ' ';
    return print_vec(beg + 1, end);
}

int main(int argc, char const *argv[])
{
    vector<int> v{10,20,30,40,50};
    print_vec(v.cbegin(), v.cend());
    return 0;
}
