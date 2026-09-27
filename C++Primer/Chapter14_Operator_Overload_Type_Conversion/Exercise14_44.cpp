/*
 *本节核心考点：std::function、标准库二元函数对象 plus/minus/multiplies/divides/modulus。
 思路：建立运算符字符到对应标准库仿函数的映射，读取两个操作数 + 运算符，执行二元运算
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

int main(int argc, char const *argv[])
{
    map<string, function<int(int, int)>> bimap;
    bimap.insert({"+", plus<int>()});
    bimap.insert({"-", minus<int>()});
    bimap.insert({"*", multiplies<int>()});
    bimap.insert({"/", divides<int>()});
    bimap.insert({"%", modulus<int>()});

    cout << bimap["+"](1, 2) << '\n';
    cout << bimap["-"](1, 2) << '\n';
    return 0;
}
