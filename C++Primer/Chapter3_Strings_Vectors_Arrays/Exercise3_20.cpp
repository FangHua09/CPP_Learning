/*
**题目描述**：读入一组整数并把它们存入一个 vector 对象，
将每对相邻整数的和输出出来。
改写你的程序，这次要求先输出第 1 个和最后 1 个元素的和，接着输出第 2 个和倒数第 2 个元素的和
，以此类推。
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

int main(int argc, char const *argv[])
{
    /*
**题目描述**：读入一组整数并把它们存入一个 vector 对象，
将每对相邻整数的和输出出来。
改写你的程序，这次要求先输出第 1 个和最后 1 个元素的和，接着输出第 2 个和倒数第 2 个元素的和
，以此类推。
*/
    vector<int> ivec;
    int i;
    while (cin >> i)
        ivec.push_back(i);

    cout << "相邻元素之和：" << endl;
    for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i)
    {
        cout << ivec[i] + ivec[i + 1] << " ";
    }
    cout << endl;

    cout << "首尾成对之和：" << endl;
    auto sz = ivec.size();
    for (decltype(sz) i = 0; i < sz / 2; ++i)
    {
        cout << ivec[i] + ivec[sz - 1 - i] << " ";
    }
    // 如果元素个数奇数，输出中间元素
    if (sz % 2 != 0)
    {
        cout << ivec[sz / 2];
    }
    cout << endl;

    return 0;
}
