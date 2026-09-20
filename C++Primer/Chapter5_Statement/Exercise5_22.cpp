
/*
练习 5.22
原题 goto 版本（书上原代码）
cpp
运行
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin; // sz<=0就跳回begin，重新调用get_size()
    }
// 当sz>0才往下执行后续代码
逻辑：反复调用get_size()，直到得到大于 0 的 sz 值才退出循环往下走。


改写方案 1：do‑while 循环（最贴合原意）
int sz;
do {
    sz = get_size();
} while (sz <= 0);
// sz>0，继续后面业务代码
do‑while 先执行一次获取 sz，条件sz<=0为真就继续循环，等价原来 goto 跳转逻辑。

改写方案 2：while 循环写法
cpp
运行
int sz = get_size();
while (sz <= 0)
{
    sz = get_size();
}

改写方案 3：for 循环写法
int sz;
for (sz = get_size(); sz <= 0; sz = get_size())
    ; //空语句，循环体什么都不做
完整可运行示例
#include <iostream>
int get_size()
{
    static int cnt = 0;
    cnt++;
    std::cout << "call get_size(), return: ";
    if(cnt <3) return 0;
    else return 10;
}

int main()
{
    int sz;
    do {
        sz = get_size();
    } while(sz <= 0);

    std::cout << "sz = " << sz << std::endl;
    return 0;
}
运行输出：
plaintext
call get_size(), return: call get_size(), return: call get_size(), return: sz = 10
*/