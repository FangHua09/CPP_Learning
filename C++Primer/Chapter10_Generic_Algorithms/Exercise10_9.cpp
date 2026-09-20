/*
题目：实现你自己的 elimDups。测试你的程序，分别在读取输入后、调用 unique 后以及调用 erase 后打印 vector 的内容。
知识点：unique 只会把相邻重复元素移到序列末尾，不会真正删除元素，也不会改变容器大小；真正删除元素要靠 vector 的成员函数 erase。
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

// 打印vector
void printVec(const vector<int>& vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

void elimDups(vector<int> &v){
    printVec(v);
    sort(v.begin(), v.end());
    printVec(v);
    auto end_unique = unique(v.begin(), v.end());
    printVec(v);
    v.erase(end_unique, v.end());
    printVec(v);
}

int main(int argc, char const *argv[])
{
    vector<int> vec{3, 3, 3, 2, 2, 1};
    elimDups(vec);
    /*
    3 3 3 2 2 1 
1 2 2 3 3 3 
1 2 3 3 3 3 
1 2 3
    */
    return 0;
}
