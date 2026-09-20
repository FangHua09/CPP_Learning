/*
题目描述：编写一个程序，使其接受本节所示的选项；输出传递给 main 函数的实参的内容。
书本示例命令行：prog -d -o ofile data0

cd "C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function"
g++ -std=c++17 Exercise6_26.cpp -o prog.exe
./prog -d -o ofile data0

预期输出
PS C:\Users\13075> cd "C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function"
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> g++ -std=c++17 Exercise6_26.cpp -o prog.exe
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> ./prog -d -o ofile data0
实参总个数 argc = 5
argv[0] : C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function\prog.exe
argv[1] : -d
argv[2] : -o
argv[3] : ofile
argv[4] : data0
*/
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
    cout << "实参总个数 argc = " << argc << endl;
    for (int i = 0; i < argc; ++i)
    {
        cout << "argv[" << i << "] : " << argv[i] << endl;
    }

    return 0;
}
