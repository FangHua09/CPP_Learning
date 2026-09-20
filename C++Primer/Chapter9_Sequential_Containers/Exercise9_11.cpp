/*
题目描述：对 6 种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

例子
#include <vector>

int main()
{
    //1. 默认构造，空vector
    std::vector<int> v1;
    // v1：不包含任何元素，size=0

    //2. n个值初始化的元素
    std::vector<int> v2(5);
    // v2：5个int，全部值初始化为0； {0,0,0,0,0}

    //3. n个指定值的元素
    std::vector<int> v3(5, 10);
    // v3：5个元素，全部是10； {10,10,10,10,10}

    //4. 拷贝构造，拷贝另一个vector
    std::vector<int> v4(v3);
    // v4：复制v3全部元素；{10,10,10,10,10}

    //5. 列表初始化（花括号）
    std::vector<int> v5{1,2,3,4};
    // v5：4个元素，1,2,3,4； {1,2,3,4}

    //6. 迭代器范围初始化
    std::vector<int> v6(v5.begin(), v5.end());
    // v6：拷贝[v5.begin(),v5.end())范围元素；{1,2,3,4}

    return 0;
}

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

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v1; //1. 默认构造，空vector

    vector<int> v2(5); //2. n个值初始化的元素

    vector<int> v3{1, 2, 3}; // 列表初始化

    vector<int> v4 = {1, 2, 3}; // 同上

    vector<int> v5 = v4; // 拷贝初始化

    vector<int> v6(v5); // 直接拷贝初始化

    vector<int> v7(v6.begin(), v7.end()); //迭代器范围的拷贝初始化

    return 0;
}
