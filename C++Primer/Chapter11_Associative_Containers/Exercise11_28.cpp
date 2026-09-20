/*
题目描述：对一个 string 到 int 的 vector 的 map，定义并初始化一个变量来保存在其上调用 find 所返回的结果。
知识点：map::find 返回值类型为容器的迭代器；map<string, vector<int>> 迭代器类型。
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
    map<string, vector<int>> m;
    // find返回 map<string, vector<int>>::iterator
    map<string, vector<int>>::iterator it = m.find("hello");

    return 0;
}
