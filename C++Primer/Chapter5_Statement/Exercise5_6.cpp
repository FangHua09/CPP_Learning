// 练习 5.6：条件运算符`?:`改写上面程序
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
    int score;
    string commnt;
    cin >> score;

    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    commnt = (score < 60) ? "F" : (score < 70 ? "D" : (score < 80 ? "C" : (score < 90 ? "B" : (score < 100 ? "A" : "A++"))));

    if (score < 60 || score == 100)
    {
        cout << commnt << '\n';
        return 0;
    }
    commnt += (((score - 50) % 10) > 7) ? "+" : (((score - 50) % 10) < 3 ? "-" : "");

    cout << commnt << '\n';
    return 0;
}
