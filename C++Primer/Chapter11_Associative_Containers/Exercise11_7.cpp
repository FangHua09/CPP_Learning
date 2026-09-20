/*
题目：定义一个 map，关键字是家庭的姓，值是一个 vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
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
    map<string, vector<string>> families;

    families["Smith"] = {"Alice", "Bob"};

    // 2. 向已有家庭增加孩子
    families["Smith"].push_back("Tom");

    // 3. 新增一个家庭
    families["Johnson"].push_back("Amy");

    for (auto &&entry : families)
    {
        cout << entry.first << '\n';
        for (auto &&value : entry.second)
        {
            cout << value << ' ';
        }
        cout << '\n';
    }

    return 0;
}
