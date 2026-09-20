/*
编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的 char 数组中。重写这个程序，连接两个标准库 string 对象。
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
    // const char *s1 = "Hello";
    // const char *s2 = "World!";
    // auto total_len = strlen(s1) + strlen(s2);
    // char *p = new char[total_len + 1];
    // strcpy(p, s1);
    // strcat(p, s2);
    // while (*p != '\0')
    // {
    //     cout << *p;
    //     ++p;
    // }
    // delete[] p;

    // ========= 第二部分：重写，拼接两个std::string对象 =========
    string s3 = "hello";
    string s4 = "world";
    string s5 = s3 + s4;
    char* p2 = new char[s5.size() + 1];
    strcpy(p2, s5.c_str());
        while (*p2 != '\0')
    {
        cout << *p2;
        ++p2;
    }
    delete[] p2;

    return 0;
}
