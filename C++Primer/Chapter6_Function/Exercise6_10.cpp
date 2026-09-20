// 编写函数，使用指针形参交换两个整数的值；调用函数，输出交换结果验证。
#include <iostream>
#include <vector>
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

using namespace std;

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp; //我们仅改变了值，这两个指针仍然指向的是原来的位置，只不过这两个位置的值交换了，除此之外还可以交换指向
}

int main(int argc, char const *argv[])
{
    int a = 666;
    int b = 999;
    swap(&a, &b);
    cout << a << " " << b << '\n';
    return 0;
}
