/*
原先map<string, vector<string>>：姓氏为 key，vector 存孩子名字。改用multimap重写。
原来 map：一个姓氏只能对应一条记录（vector 存多个孩子）。multimap：允许同一个 key（姓氏）保存多条记录，每条记录存一个孩子名字。
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
using namespace std;

int main(int argc, char const *argv[])
{
    // key：姓氏，value：孩子名
    multimap<string, string> families;
    families.insert({"Smith", "Alice"});
    families.insert({"Smith", "Bob"});
    families.insert({"Smith", "Tom"});
    families.insert({"Johnson", "Amy"});

    // 遍历multimap
    for (auto &p : families)
    {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
