/*
定义一个 map，将单词与一个行号的 list 关联，list 中保存的是单词所出现的行号。
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
    string word;
    // map: key是单词string；value是保存行号的list<int>
    map<string, list<int>> word_lines;

    word_lines["test"] = {1, 2, 3};
    // 示例：填充数据
    word_lines["hello"].push_back(1);
    word_lines["hello"].push_back(3);
    word_lines["world"].push_back(2);

    // 遍历输出
    for (const auto &item : word_lines)
    {
        cout << item.first << " : ";
        for (auto line : item.second)
        {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}
