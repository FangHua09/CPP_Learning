/*
编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector 的内容，验证你的程序的正确性。

stable_sort 是稳定排序算法，谓词判定为相等的元素会保持排序前的相对顺序。
本题中长度相同的单词视为相等，排序后保留了之前字典序的相对位置。
自定义谓词可以灵活改变排序的依据，不局限于默认的 < 比较。

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

// 打印vector
void printVec(const vector<string>& vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

// 谓词
bool isShorter(const string& s1, const string& s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2; // 长度一样才字典序
    }else return s1.size() < s2.size(); // 长度不一样小的在前面
}

void elimDups(vector<string> &v){
    printVec(v);
    sort(v.begin(), v.end(), isShorter);
    printVec(v);
    auto end_unique = unique(v.begin(), v.end());
    printVec(v);
    v.erase(end_unique, v.end());
    printVec(v);

}

int main(int argc, char const *argv[])
{
    vector<string> words1 = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words1);

    // ----------------------------

    // stable_sort即稳定保持指定排序规则后内部的（内部的是相同的意思）顺序（字典序）
    return 0;
}
