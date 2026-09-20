/*
使用 reverse_iterator 逆序打印一个 vector。
知识点
反向迭代器从容器尾部向头部遍历，rbegin() 返回指向尾元素的反向迭代器，rend() 返回指向首元素前一位置的反向迭代器。
对反向迭代器执行++操作，会向容器头部移动，天然实现逆序遍历。
crbegin()/crend() 是 const 反向迭代器，只读遍历更安全。
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
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    // 反向迭代器逆序遍历

    // 注意区分 这里rbegin已经指向最后一个元素，逻辑名字位置不变，只是物理解释变了
    for(auto it = vec.rbegin(); it != vec.rend(); it++){
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
