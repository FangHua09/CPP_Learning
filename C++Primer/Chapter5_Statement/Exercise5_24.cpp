// ：修改程序，当第二个数是 0 时抛出异常。不要写 catch 子句，输入 0 观察现象。
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

int main(int argc, char const *argv[])
{
     int a, b;
    std::cin >> a >> b;
    if (b == 0)
    {
        throw std::runtime_error("divisor is zero");
    }
    std::cout << a / b << std::endl;
    return 0;
}
/*
terminate called after throwing an instance of 'std::runtime_error'
  what():  divisor is zero
  原理：异常没有被 catch 捕获，程序调用std::terminate()终止运行。
*/
