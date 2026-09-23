/*
定义vector<String>多次 push_back，观察拷贝次数
main 测试代码：
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
    vector<string> vec;
    cout << "capacity: " << vec.capacity() << '\n';
    vec.push_back(string("aaa"));
    cout << "capacity: " << vec.capacity() << '\n';
    vec.push_back(string("aaa"));
    cout << "capacity: " << vec.capacity() << '\n';
    vec.push_back(string("aaa"));
    cout << "capacity: " << vec.capacity() << '\n';
    vec.push_back(string("aaa"));
    cout << "capacity: " << vec.capacity() << '\n';
    vec.push_back(string("aaa"));
    cout << "capacity: " << vec.capacity() << '\n';
    return 0;
}
/*
capacity: 0
capacity: 1
capacity: 2
capacity: 4
capacity: 4
capacity: 8
*/