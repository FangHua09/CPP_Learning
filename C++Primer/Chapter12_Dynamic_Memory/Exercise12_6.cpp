/*
题目描述：编写函数，返回一个动态分配的 int 的 vector。将此 vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将 vector 传递给另一个函数，打印读入的值。记得在恰当的时刻 delete vector。
知识点：new分配容器；动态内存管理；手动delete释放堆内存。
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

// 返回动态分配的vector<int>
vector<int>* create_vec(){
    return new vector<int>(); // 默认构造
}

// // 读取标准输入存入vector
void read_vec(vector<int>* vp) {
    int n;
    while(cin >> n) vp->push_back(n);
}

// 打印vector内容
void print_vec(vector<int>* vp)
{
    for (auto v : *vp)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int>* vp = create_vec();
    read_vec(vp);
    print_vec(vp);
    delete vp;
    return 0;
}
