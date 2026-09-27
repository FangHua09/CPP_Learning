/*
 *题目：修改程序，统计：长度 1~9 的单词总数、长度≥10 的单词总数。
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
        return str.size() <= val;
    }
};

int main(int argc, char const *argv[])
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
    auto lower9 = count_if(words.cbegin(), words.cend(), StringLenEqual(9));
    auto upper10 = words.size() - lower9;
    cout << "lower9: " << lower9 << " upper10: " << upper10 << '\n';
    return 0;
}
