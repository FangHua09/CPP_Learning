/*

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

int main(int argc, char const *argv[])
{
    allocator<string> alloc; // 这是分配器 不是指针
    auto const p = alloc.allocate(10); // 分配了十个string大小指向没有初始化的raw内存
    // 利用栈上创建的指针去干活
    auto q = p;

    string s;
    while(cin >> s && q != q + 10) {
        alloc.construct(q++, "test");
    }
    const size_t size = q - p;

    for(auto beg = p; beg != beg + size; beg++){
        // auto忽略顶层const
        cout << *beg << ' ';
    }

    // 销毁之前必须destroy
    // 此时p指向第一个， q指向尾后，而p是alloc分配的顶层const
    while(q != p){
        alloc.destroy(--q);
    }

    alloc.deallocate(p, 10); // 传入p是alloc分配的顶层const， 并且指明当初分配给它的空间的大小单位


    return 0;
}
