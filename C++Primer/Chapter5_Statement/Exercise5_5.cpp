// 练习 5.5：if‑else 数字成绩转字母成绩
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

    if (score < 60)
    {
        commnt = scores[0];
        cout << commnt << '\n';
        return 0;
    }
    else if (score == 100)
    {
        commnt = scores[5];
        cout << commnt << '\n';
        return 0;
    }
    else
    {
        commnt += scores[(score - 50) / 10];
        if (score % 10 > 7)
            commnt += "+";
        else if (score % 10 < 3)
            commnt += "-";
        cout << commnt << '\n';
        return 0;
    }
    return 0;
}
