//**题目描述**：请使用迭代器重做 3.3.3 节（第 94 页）的
/// 第一个练习（练习 3.16，输出各个 vector 的 size 和内容）。
#include <iostream>
#include <vector>
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
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    auto print = [](auto &vec)
    {
        cout << "size: " << vec.size() << " 元素： ";

        for (auto i = vec.begin(); i != vec.end(); i++)
        {
            cout << *i << " ";
        }
        cout << '\n';
    };

    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
    print(v7);
    return 0;
}
