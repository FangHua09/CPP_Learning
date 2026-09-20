// 题目描述：修改 arrPtr 函数，使其返回数组的引用。
#include <iostream>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// 修改为返回数组的引用
int (&arrPtr(int i))[5]
{
    return (i % 2) ? odd : even;
}

int main()
{
    auto &ref = arrPtr(1);
    for(auto x : ref)
        cout << x << " ";
    return 0;
}