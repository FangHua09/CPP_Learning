/*
题目描述：
编写函数，接受一个istream&参数，返回值类型也是istream&。
此函数须从给定流中读取数据，直至遇到文件结束标识时停止。
它将读取的数据打印在标准输出上。
完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。
*/

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

istream& read_print(istream& is) {
    int a;
    while(is >> a) cout << a << ' '; // 直到读到文件结束标识符

    //返回流之前对流复位，使其处于有效状态
    is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);

    return is;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
