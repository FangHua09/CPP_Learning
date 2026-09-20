
/*
如果 f 的参数改为 const numbered &s，会怎样？改变输出吗？
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

// void f(const numbered &s) { cout << s.mysn << endl; } // 这里是引用传递， 则只有在变量拷贝初始化时候会递增， 在前者的基础上递增
void f(numbered s) { cout << s.mysn << endl; } // 这里是值传递 那么调用的时候还会进行拷贝一次，不过在自己身上加， a.mybn = a.mybn + 1

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
