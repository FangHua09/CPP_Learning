/*
编写一段程序，把练习 3.13 中 vector 对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不对，回过头重新学习 3.3.1 节（第 87 页）直到弄明白错在何处为止。
*/

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

    // lambda表达式 匿名函数
    auto print = [](auto &vec)
    {
        cout << "size : " << vec.size() << " 元素： ";
        for (auto &&i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
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
