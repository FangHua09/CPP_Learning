/*
题目描述：改写 6.3.2 节练习中使用递归输出 vector 内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出 vector 对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
使用NDEBUG预处理宏控制调试输出；定义NDEBUG就关闭调试信息；不定义就开启调试打印。

开启调试（不定义 NDEBUG）
编译命令：g++ main.cpp -o main
运行输出：
[debug] 剩余元素数量: 4
10 [debug] 剩余元素数量: 3
20 [debug] 剩余元素数量: 2
30 [debug] 剩余元素数量: 1
40 [debug] 剩余元素数量: 0

关闭调试（定义 NDEBUG 宏）
编译命令：g++ main.cpp -o main -DNDEBUG
#ifndef NDEBUG内代码全部被预处理器删掉，无调试打印。
运行输出：
10 20 30 40
*/
#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
// 在这里写辅助调试
#ifndef NDEBUG
cerr << "vec还剩下 ：" << (end - beg) << " 个元素" << endl;
#endif

    if (beg == end)
        return;
    cout << *beg << " ";
    print_vec(beg + 1, end);
}

int main()
{
    vector<int> vec{10,20,30,40};
    print_vec(vec.cbegin(), vec.cend());
    return 0;
}