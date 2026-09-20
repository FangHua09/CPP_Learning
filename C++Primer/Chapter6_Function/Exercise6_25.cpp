// 题目描述：编写一个 main 函数，令其接受两个实参。把实参的内容连接成一个 string 对象并输出出来。

/*


命令行输入：
cd "C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function"
g++ -std=c++17 Exercise6_25.cpp -o a.exe
./a.exe hello world
预期输出：
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> g++ -std=c++17 Exercise6_25.cpp -o a.exe
PS C:\Users\13075\CLionProjects\CalrCourse\C++Primer\Chapter6_Function> ./a.exe hello world
helloworld
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
    // argc 参数个数，argv 字符串数组，argv[0]程序名，argv[1]第一个实参，argv[2]第二个实参
     if (argc < 3)
    {
        cout << "请传入两个命令行参数！" << endl;
        return -1;
    }
    string s(argv[1]);
    s += argv[2];
    cout << s << endl;
    return 0;
}
