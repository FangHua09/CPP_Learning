/*
**题目描述**
重做上一题，但读取 `string` 序列存入 `list` 中。
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
    list<string> lst = {"he", "she", "it", "it", "it"};
    string s = "it";

    cout << "it出现的次数：  " << count(lst.begin(), lst.end(), s) << '\n';
    return 0;
}
