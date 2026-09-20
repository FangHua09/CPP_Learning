/*
题目描述
设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。
构造函数应该能处理不同数据格式，如 January 1, 1900、1/1/1990、Jan 1 1900 等。
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

class Date
{
public:
    unsigned year;
    unsigned month;
    unsigned day;

    Date(const string &s);

private:
    int month_to_num(const string &mon_str)
    {
        const static vector<string> months{
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"};

        for (size_t i = 0; i < months.size(); i++)
        {
            if (months[i] == mon_str)
            {
                return (i % 12) + 1;
            }
        }
        return 0;
    }
};

Date::Date(const string &s)
{
    // 分支一 /
    if (s.find('/') != string::npos)
    {
        size_t p1 = s.find('/');
        size_t p2 = s.find('/', p1 + 1);
        month = stoi(s.substr(0, p1));
        day = stoi(s.substr(p1 + 1, p2 - p1 - 1)); //substr是起始位置和长度（差）
        year = stoi(s.substr(p2 + 1)); 
        return;
    }

    // 分支二 英文月份
    size_t p1 = s.find(' ');
    month = month_to_num(s.substr(0, p1));
    size_t p2 = s.find_first_of(" ,", p1 + 1); // find系列的是从pos位置开始找
    day = stoi(s.substr(p1 + 1, p2 - p1 - 1));
    size_t p3 = s.find_last_of(' ');      // 最后一个空格之后是年份
    year = stoi(s.substr(p3 + 1));
};

int main()
{
    Date d1("January 1, 1900");
    Date d2("1/1/1990");
    Date d3("Jan 1 1900");
    Date d4("December 25, 2023");
    Date d5("12/25/2023");

    cout << d1.year << "-" << d1.month << "-" << d1.day << endl;
    cout << d2.year << "-" << d2.month << "-" << d2.day << endl;
    cout << d3.year << "-" << d3.month << "-" << d3.day << endl;
    cout << d4.year << "-" << d4.month << "-" << d4.day << endl;
    cout << d5.year << "-" << d5.month << "-" << d5.day << endl;
    return 0;
}