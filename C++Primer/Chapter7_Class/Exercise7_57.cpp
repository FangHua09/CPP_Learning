// Account：账号名，金额；静态数据成员：年利率 rate；静态成员函数修改利率。
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

class Account
{
public:
void calculate() {amount += amount * rate;}

Account(string owner, double amount) : owner(owner), amount(amount){}

static double get_rate() {return rate;}

static void set_rate(double rate) {rate = rate;}
private:
    string owner;
    static double rate;
    double amount;
};

// 类外定义静态成员
double Account::rate = 0.0;