/*
题目描述：实现你自己版本的单词转换程序。知识点：map保存单词转换映射；读取规则文件构建映射；读取文本文件，查找并替换单词。
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

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> map;
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

const string &transform(const map<string, string> &build_map, const string &word)
{
    std::map<std::string, std::string>::const_iterator it;
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
    map<string, string> map = build_map(map_file);
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
