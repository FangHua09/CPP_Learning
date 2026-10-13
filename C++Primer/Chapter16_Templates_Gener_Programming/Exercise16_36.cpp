/*
 *template <typename T> void f1(T, T);
 template <typename T1, typename T2> void f2(T1, T2);
 int i = 0, j = 42, *p1 = &i, *p2 = &j;
 const int *cp1 = &i, *cp2 = &j;
 变量类型：
 p1,p2：int*
 cp1,cp2：const int*


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

#include <iostream>
using namespace std;

template <typename T>
void f1(T, T)
{
}

template <typename T1, typename T2>
void f2(T1, T2)
{
}

int main()
{
    int i = 0;
    int j = 42;
    int *p1 = &i;
    int *p2 = &j;
    const int *cp1 = &i;
    const int *cp2 = &j;

    //(a) f1(p1, p2); ✅合法，T=int*
    f1(p1, p2);

    //(b) f2(p1, p2); ✅合法 T1=int*, T2=int*
    f2(p1, p2);

    //(c) f1(cp1, cp2); ✅合法 T=const int*
    f1(cp1, cp2);

    //(d) f2(cp1, cp2); ✅合法 T1=const int*, T2=const int*
    f2(cp1, cp2);

    //(e) f1(p1, cp1); // ❌【编译报错！推导冲突】
    // f1(p1, cp1);
    // p1: int* , cp1: const int* 底层const并不会丢弃
    // 自动推导不会自动转类型来统一T，一个想要T=int*,一个T=const int*，冲突
    // f1(p1, cp1);

    // 想要e通过，必须显式指定模板参数
    f1<const int *>(p1, cp1);

    //(f) f2(p1, cp1); ✅合法 T1=int*, T2=const int*
    f2(p1, cp1);

    return 0;
}
