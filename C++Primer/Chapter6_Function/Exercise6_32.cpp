// 题目描述：下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
#include <iostream>
using namespace std;

//合法
int &get(int *arry, int index) {
    return arry[index];
}

int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i; //返回左值引用，可以做左值赋值

    for(auto x : ia)
        cout << x << " ";
    return 0;
}