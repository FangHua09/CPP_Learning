/*
题目描述：使用上一题定义的 multimap 编写一个程序，按字典序打印作者列表和他们的作品。
知识点：multimap 内部按键自动升序（字典序）存储；equal_range获取同一个 key 的全部元素区间。
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
    multimap<string, string> books;
    books.insert({"Lu Xun", "Diary of a Madman"});
    books.insert({"Lu Xun", "The True Story of Ah Q"});
    books.insert({"Mo Yan", "Red Sorghum"});


    // 打印multimap？每个相同的key都串着一条链表，字典升序存储
    for (auto beg = books.cbegin(); beg != books.cend(); beg++){
        cout << "Author: " << beg->first << '\n';
        // 遍历beg->second的时候`equal_range`获取同一个 key 的全部元素区间。
        auto range = books.equal_range(beg->second);
        for(auto beg = range.first; beg != range.second; range.first++){
            cout << beg->second << ' ';
        }
    }
    return 0;
}
