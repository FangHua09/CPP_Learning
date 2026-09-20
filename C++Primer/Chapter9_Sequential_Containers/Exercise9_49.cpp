/*
题目：字母有上出头部分（b,d,f,h,k,l,t）、下出头部分（g,p,q,y）。读单词文件，输出最长的既不含上出头、也不含下出头字母的单词。
思路：
把所有禁止字符放到字符串bad_chars = "bdfhkltgpqy"
读取每个单词，用find_first_of判断：如果返回string::npos，说明单词里没有禁止字符
记录符合条件的最长单词
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
    string bad_chars = "bdfhkltgpqy";
    ifstream ifs(R"(C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter9_Sequential_Containers\Exercise9_49.txt)");
    if (!ifs)
        cout << "打开失败！" << '\n';
    string bestWord;
    string::size_type bestLen = 0; // 都需要初始化

    string word;
    while (ifs >> word)
    {
        if ((word.find_first_of(bad_chars) == string::npos) && (word.length() > bestLen))
        {
            bestLen = word.length();
            bestWord = word;
        }
    }

    cout << "bestWord : " << bestWord << '\n'; // bestWord : concession
    return 0;
}
