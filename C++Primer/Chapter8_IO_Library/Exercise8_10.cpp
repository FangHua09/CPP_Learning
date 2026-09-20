// 读取文件每行存入`vector<string>`，再用`istringstream`从 vector 逐个读取单词。
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
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
    // 从文件中读取每行保存到容器

    ifstream ifs(R"(C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library\Exercise8_10.txt)");
    if (!ifs.is_open())
    {
        cerr << "文件打开失败！" << endl;
        return -1;
    }

    vector<string> v;
    string line;
    while (getline(ifs, line))
        v.push_back(line);

    // 按行保存到容器以后需要用iss从容器按单词读取string元素
    // 也就是容器每个元素都需要逐一绑定iss

    for (auto &&line : v)
    {
        istringstream iss(line);
        // 然后调用上题的打印函数
        string word;
        while (iss >> word)
            cout << word << '\n';
    }

    /*
    Alice
13800138000
13900139000
Bob
13700137000
Charlie
13600136000
13500135000
13400134000
    */

    return 0;
}
