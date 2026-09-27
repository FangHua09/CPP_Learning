/*
 *练习 14.35：ReadString 类，从 istream 读一行，失败返回空 string

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