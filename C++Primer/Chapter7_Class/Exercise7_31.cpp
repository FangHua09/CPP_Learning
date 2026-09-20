/*
# 练习 7.31

> 
> 定义一对类 X 和 Y，其中 X 包含一个指向 Y 的指针，而 Y 包含一个类型为 X 的对象。
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

//假如要使用不完全类型的指针，就需要前向声明
class Y;

class X{
    Y* pY;
};

class Y{
    X x;
};

int main(int argc, char const *argv[])
{
    Y y;
    X x;
    /*
    !(Test-Path output)) { mkdir output }; g++ -g Exercise7_31.cpp -o output/Exercise7_31.exe; ./output/Exercise7_31.exe
Exercise7_31.cpp:26:5: error: 'Y' does not name a type
   26 |     Y* pY;
      |     ^
./output/Exercise7_31.exe: The term './output/Exercise7_31.exe' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.
    */
    return 0;
}
