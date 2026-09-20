/*
题目：numbered类，默认构造给每个对象生成唯一序号存入mysn；使用合成拷贝控制成员。函数void f(numbered s) { cout << s.mysn << endl; }
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

class numbered
{
public:
    numbered() : mysn(0)
    {
        
    }
    numbered(const numbered& n){
        this->mysn = n.mysn + 1;
    }

    size_t mysn;
};

void f(numbered s) { cout << s.mysn << endl; }

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
