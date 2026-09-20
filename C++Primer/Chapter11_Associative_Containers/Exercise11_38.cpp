/*
题目：用 unordered_map 重写单词计数程序 和 单词转换程序。
*/
// 单词计数程序（原 11.1 节）
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

// （1）单词计数程序（原 11.1 节）
// 原代码使用map<string,size_t>统计单词出现次数；改成unordered_map。
// int main(int argc, char const *argv[])
// {
//     unordered_map<string, size_t> umap;
//     string word;
//     while (cin >> word)
//     {
//         ++umap[word];
//     }

//     // unordered_map遍历是无序的,同样是pair
//     for (const auto &w : umap)
//     {
//         cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
//     }
//     return 0;
// }

/*
## （2）单词转换程序（原 11.3.6 节，11.33 那道题）

只需要把所有`map<string,string>`替换成`unordered_map<string,string>`即可，其余逻辑不变。
*/



unordered_map<string,string> build_map(ifstream &map_file)
{
    unordered_map<string,string> map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
        {
            map[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("读入map文件错误");
        }
    }
    return map;
}

const string &transform(const unordered_map<string,string> &build_map, const string &word)
{
    unordered_map<string,string>::const_iterator it;
    if ((it = build_map.find(word)) != build_map.end())
    {
        return it->second;
    }
    else
    {
        return word;
    }
}

void work_transform(ifstream &map_file, ifstream &input)
{
    unordered_map<string,string> map = build_map(map_file);
    string line;
    while (input >> line)
    {
        stringstream ss(line); // 把读入进来的一行转换成流
        string word;
        bool first = true;
        while (ss >> word)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                cout << ' ';
            }
            cout << transform(map, word);
        }
        cout << ' ';
    }
}

int main(int argc, char const *argv[])
{
    // Exercise11_33input.txt：转换规则文件
    // Exercise11_33output.txt：待转换原文文件
    ifstream rule_file(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter11_Associative_Containers\Exercise11_33input.txt)");
    ifstream input_file(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter11_Associative_Containers\Exercise11_33output.txt)");
    if (!rule_file || !input_file)
    {
        throw runtime_error("文件打开失败");
    }
    work_transform(rule_file, input_file);
    rule_file.close();
    input_file.close();
    return 0;
}
