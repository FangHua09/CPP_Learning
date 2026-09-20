/*
编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的是整数。使用istream_iterator读取输入文件。使用ostream_iterator将奇数写入第一个输出文件，每个值之后都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。
知识点
命令行参数argc/argv接收文件名：argv[1]输入文件，argv[2]奇数输出文件，argv[3]偶数输出文件。
istream_iterator<int> 读取输入文件所有整数。
遍历整数按奇偶分流，分别写入两个ostream_iterator：奇数用空格分隔，偶数用换行符分隔。
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
#include <functional>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        cerr << "用法：程序名 输入文件 奇数输出文件 偶数输出文件" << endl;
        return 1;
    }

    ifstream ifs(argv[1]); // 输入文件
    if (!ifs)
    {
        cerr << "打开输入文件失败" << endl;
        return 1;
    }
    ofstream ofs_odd(argv[2]);
    ofstream ofs_even(argv[3]);

    if (!ofs_odd || !ofs_even)
    {
        cerr << "打开输出文件失败" << endl;
        return 1;
    }

    istream_iterator<int> in_iter(ifs), eof;
    ostream_iterator<int> out_odd(ofs_odd, " ");
    ostream_iterator<int> out_even(ofs_even, "\n");

    // while (in_iter != eof)
    // {
    //     if (*in_iter % 2 == 0)
    //     {
    //         out_even = *in_iter++;
    //     }
    //     else
    //     {
    //         out_odd = *in_iter++;
    //     }
    // }

    vector<int> vec(in_iter, eof);
    // 利用划分拷贝函数
    partition_copy(vec.begin(), vec.end(), out_odd, out_even, [](int val)
                   { return val % 2 != 0; });

    return 0;
}
