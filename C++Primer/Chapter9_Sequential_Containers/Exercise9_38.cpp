// ：编写程序，探究在你的标准库实现中，vector 是如何增长的。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    cout << "size | capacity" << endl;
    for(int i = 0; i < 50; ++i)
    {
        vec.push_back(i);
        cout << vec.size() << "      " << vec.capacity() << endl;
    }
    return 0;
}

/*
size | capacity
1      1
2      2
3      4
4      4
5      8
6      8
7      8
8      8
9      16
10      16
11      16
12      16
13      16
14      16
15      16
16      16
17      32
18      32
19      32
20      32
21      32
22      32
23      32
24      32
25      32
26      32
27      32
28      32
29      32
30      32
31      32
32      32
33      64
34      64
35      64
36      64
37      64
38      64
39      64
40      64
41      64
42      64
43      64
44      64
45      64
46      64
47      64
48      64
49      64
50      64
*/
