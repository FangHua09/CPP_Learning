/*
题目描述：编写程序，将一个 list 中的 char* 指针（指向 C 风格字符串）元素赋值给一个 vector 中的 string。
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
    list<char*>l; // 指向c风格字符串的元素类型
    vector<string> v; // string为元素类型；

    //l.push_back("Hello");   C++ forbids converting a string constant to 'std::__cxx11::list<char*>::value_type' {aka 'char*'} 
    // 我们不可以用一个const char*去初始化一个char*类型的参数

    //char c[] = "hello"; //这里是合法的，但是此时c的类型是const char*
    char c[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // 此时c类型才是char *
    
    l.push_back(c);
    v.assign(l.begin(), l.end());

    for (auto &&i : v)
    {
        cout << i << '\n';
    }
    
    // Hello

    return 0;
}
