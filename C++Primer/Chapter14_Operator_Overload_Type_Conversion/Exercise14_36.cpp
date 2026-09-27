/*
 *用上一题的 ReadString 读取标准输入，每行存入 vector<string>
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

class ReadString
{
public:
    ReadString(istream &is = cin) : is(is) {}
    string operator()()
    {
        string s;
        getline(is, s);
        if (is)
            return s;
        else
            return string();
    }

private:
    istream &is;
};

int main(int argc, char const *argv[])
{
    vector<string> vec;
    ReadString read;
    string line;
    while (!(line = read()).empty())
    {
        vec.push_back(line);
    }

    //读到 EOF 时read()返回空字符串，循环终止。
    
    return 0;
}
