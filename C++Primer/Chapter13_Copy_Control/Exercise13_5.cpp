/*
编写HasPtr拷贝构造函数，要求深拷贝，为 ps 分配新 string：
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

class HasPtr
{
public:
    // 单参数构造
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

    // 拷贝构造函数：深拷贝
    HasPtr(const HasPtr& orig){
        ps = new string(*(orig.ps));
        i = orig.i;
    }

private:
    string *ps;
    int i;
};