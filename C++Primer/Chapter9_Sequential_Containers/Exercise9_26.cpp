/*
使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。
使用单迭代器版本的 erase 从 list 中删除奇数元素，
从 vector 中删除偶数元素。
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
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
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(begin(a), end(a));

    list<int> lst(begin(a), end(a));


    for (auto iterLst = lst.begin(); iterLst != lst.end(); ++iterLst) {
        if(*iterLst % 2 == 1) lst.erase(iterLst);
    }

    for (auto iterVec = vec.begin(); iterVec != vec.end(); ++iterVec) {
        if(*iterVec % 2 == 0) vec.erase(iterVec);
    }
    

    cout << "list(保留偶数): ";
    for (auto x : lst)
        cout << x << " ";
    cout << "\nvector(保留奇数): ";
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    return 0;
}
