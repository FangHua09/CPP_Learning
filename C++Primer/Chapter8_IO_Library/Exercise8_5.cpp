// **题目描述**：重写上面的程序，将每个单词作为一个独立的元素进行存储。
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

/*
**题目描述**：编写函数，以读模式打开一个文件，
将其内容读入到一个`string`的`vector`中，
将每一行作为一个独立的元素存于 vector 中。
*/
void read_file_lines(const string &path, vector<string> &v)
{
    ifstream ifs(path);

    if (ifs)
    {
        string line;
        // while (getline(ifs, line))
        // {
        //     v.push_back(line); // 按行划分
        // }

        while(ifs >> line) {
            v.push_back(line); // 按空格划分
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<string> v;
    // C++11 原始字符串字面量 R"(path)"
    read_file_lines(R"(C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library\Exercise8_4.txt)", v);
    for (auto &&i : v)
    {
        cout << i << '\n';
    }

    /*
    apple banana
    cat dog
    hello world
(base) PS C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library>
    */

    /*
    apple
    banana
    cat
    dog
    hello
    world
(base) PS C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library> 
    */

    return 0;
}
