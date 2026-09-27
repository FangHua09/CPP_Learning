/*
 *知识点：函数对象（仿函数），operator()重载，作为标准算法的谓词。
 练习 14.38
 题目：编写类，检查 string 长度是否等于阈值；统计文件中长度 1~10 的单词数量。
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
#include <memory>
using namespace std;

class StringLenEqual
{
private:
    int val;

public:
    StringLenEqual(int val) : val(val) {} // 作为阈值val
    bool operator()(const string &str)
    {
        // 这里的str是用于遍历的时候调用的
        return str.size() == val;
    }
};

int main()
{
    std::ifstream fin(R"(D:\dev\workspace\C++Learning\C++Primer\Chapter14_Operator_Overload_Type_Conversion\Exercise14_38.txt)");
    if (!fin)
    {
        std::cerr << "cannot open file" << std::endl;
        return -1;
    }
    std::string word;
    std::vector<std::string> words;
    while (fin >> word)
    {
        words.push_back(word);
    }
    // 统计长度1~10
    for (size_t i = 1; i <= 10; ++i)
    {
        auto cnt = std::count_if(words.cbegin(), words.cend(), StringLenEqual(i));
        std::cout << "长度为" << i << "的单词：" << cnt << std::endl;
    }
    return 0;
}