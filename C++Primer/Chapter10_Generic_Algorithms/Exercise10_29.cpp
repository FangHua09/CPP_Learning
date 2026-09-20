/*
编写程序，使用流迭代器读取一个文本文件，存入一个 vector 中的 string 里。
知识点
std::istream_iterator<T> 是输入流迭代器，可以绑定到输入流（文件流、标准输入等），按空白符分隔读取类型为T的数据。
默认构造的流迭代器代表流结束（EOF），可以和起始迭代器构成完整的读取范围。
可以直接用流迭代器范围初始化容器，也可以配合copy+back_inserter写入。
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
    ifstream ifs(R"(C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter10_Generic_Algorithms\Exercise10_29.txt)");
    if (!ifs)
    {
        cerr << "打开文件失败" << endl;
        return 1;
    }

    istream_iterator<string> in_iter(ifs), eof;

    // 流迭代器范围直接初始vec
    // vector<string> vec(in_iter, eof);

    // 流迭代器传入copy + back_inserter
    vector<string> vec;
    copy(in_iter, eof, back_inserter(vec));

    // 打印验证
    for (const auto &s : vec)
        cout << s << " ";
    cout << endl;
    return 0;
}
