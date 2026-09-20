// 判断一个 vector 是否是另一个 vector 的前缀
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

bool isPrefix(const vector<int> &v1, const vector<int> &v2)
{
    for (auto v1i = v1.begin(), v2i = v2.begin(); (v1i != v1.end()) && (v2i != v2.end()); v1i++, v2i++)
    {
        if (*v1i != *v2i)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v3 = {0, 1, 2};

    cout << isPrefix(v1, v2) << '\n';
    cout << isPrefix(v1, v3) << '\n';
    cout << isPrefix(v3, v2) << '\n';
    return 0;
}
