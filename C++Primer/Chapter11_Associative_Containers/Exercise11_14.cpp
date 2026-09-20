/*
题目描述：扩展你在 11.2.1 节练习（第 378 页）中编写的孩子姓到名的 map，添加一个 pair 的 vector，保存孩子的名和生日。
知识点：map<string, vector<pair<string,string>>>，value 是 vector，vector 里面存放 pair（名字，生日）。
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
    // key：姓氏；value：vector<pair<孩子名，生日>>
    map<string, vector<pair<string, string>>> families;

    families["Smith"].push_back({"Alice", "2010-01-01"}); // push_back才可以写初始化列表
    families["Smith"].emplace_back("Bob", "2012-05-15"); // emplace_back() 直接写构造所需的参数即可

        // 已有家庭新增孩子
        families["Smith"].emplace_back("Tom", "2015-08-20");
    
        // 新增家庭
        families["Johnson"].emplace_back("Amy", "2011-11-30");

        // 打印
        for (auto &&entry : families)
        {
            cout << entry.first << '\n';
            for (auto &&child : entry.second)
            {
                // 这里child是一个vec内的元素（pair）
                cout << child.first << " " << child.second << '\n';
            }
            cout << '\n';
            
        }
        
    return 0;
}
