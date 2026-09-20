// 重写上一题的函数，这次使用位置和长度来管理 string，并只使用 insert。

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

string add_prefix_suffix_insert(string name, const string &prefix, const string &suffix)
{
    // auto len = name.length(); // 保存时机错误
    name.insert(0, prefix);
    auto len = name.length();
    name.insert(len, suffix);
    return name;
}

int main(int argc, char const *argv[])
{
    string name = "Smith";
    cout << name.length() << "  " << name.size() << '\n';
    string result = add_prefix_suffix_insert(name, "Mr.", " Jr.");
    cout << result << endl;
    return 0;
}
