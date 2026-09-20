/*
题目描述：重做上一题，这次使用shared_ptr而不是内置指针。
知识点：shared_ptr智能指针，自动管理内存，无需手动 delete，引用计数。
解答
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

// 返回动态分配的shared_ptr<vector<int>>
shared_ptr<vector<int>> create_vec()
{
    return make_shared<vector<int>>(); // 默认构造
}

// // 读取标准输入存入vector
void read_vec(shared_ptr<vector<int>> vp)
{
    int n;
    while (cin >> n)
        vp->push_back(n);
}

// 打印vector内容
void print_vec(shared_ptr<vector<int>> vp)
{
    for (auto v : (*vp))
    {
        cout << v << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    shared_ptr<vector<int>> vp = create_vec();
    read_vec(vp);
    print_vec(vp);
    return 0;
}