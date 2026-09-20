/*
## 练习 1.19

> 
> 修改打印范围数字程序，处理**第一个输入数大于第二个**的情况（交换大小，保证从小到大输出）
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
    int a, b;
    std::cin >> a >> b;
    if(a > b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i <= b; i++)
    {
        std::cout << i << '\n';     
    }
    
    return 0;
}
