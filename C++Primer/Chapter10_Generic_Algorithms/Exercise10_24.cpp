/*
给定一个 string，使用 `bind` 和 `check_size` 在一个 int 的 vector 中查找第一个大于 string 长度的值。
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
using namespace std;
using namespace std::placeholders;
bool check_size(int val, string::size_type len){
    return val > len;
}

int main(int argc, char const *argv[])
{
    // 将二元函数转换为算法要求的**一元谓词**。
    vector<int> vec = {1, 3, 5, 7, 9, 11};
    string s = "hello"; // 长度为5
    //`std::placeholders::_1` 是占位符，表示调用生成的可调用对象时，传入的第一个参数会填充到这个位置。
    auto find_if_count = find_if(vec.begin(), vec.end(), bind(check_size, _1, vec.size()));
    cout << *find_if_count << '\n';
    
    return 0;
}
