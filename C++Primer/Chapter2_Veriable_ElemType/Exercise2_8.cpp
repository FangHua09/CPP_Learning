/*
练习 2.8
题目：请利用转义序列编写一段程序，
要求先输出 2M，然后转到新一行。修改程序使其先输出
2，然后输出制表符，再输出 M，最后转到新一行。

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

int main(int argc, char const *argv[])
{
    /*
    请利用转义序列编写一段程序，
    要求先输出 2M，然后转到新一行。
    2，修改程序使其先输出2，然后输出制表符，再输出 M，最后转到新一行。
    */
    std::cout << "2M\n" << '\n';
              
    std::cout << "2" << '\t' << "M" << '\n';

    /*
    2M

2       M
    */

    return 0;
}
