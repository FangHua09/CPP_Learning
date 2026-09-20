// 练习 1.8 判断 4 条语句合法性
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
    // ①
    std::cout << "/*";
    // ②
    std::cout << "*/";
    // ③
    //std::cout << /*  "*/ "  */;
    // ④
    //std::cout << /*  "*/ " /*  " /*"  */;

    return 0;
}
