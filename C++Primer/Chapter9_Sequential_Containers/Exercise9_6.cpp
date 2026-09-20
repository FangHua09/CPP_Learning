/*
题目描述：下面程序有何错误？你应该如何修改它？
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
                    iter2 = lst1.end();
while (iter1 < iter2)  

解答
错误原因
list是双向链表，它的迭代器属于双向迭代器，不支持<、>大小比较运算；双向迭代器只支持相等比较 == / !=。<运算符仅随机访问迭代器（vector/deque）可用。
修改后代码
#include <list>

int main()
{
    std::list<int> lst1;
    std::list<int>::iterator iter1 = lst1.begin(),
                            iter2 = lst1.end();
    while (iter1 != iter2) // 将 < 修改为 !=
    {
        // ...
        ++iter1;
    }
    return 0;
}


核心要点
vector/deque 随机访问迭代器：支持 < > == !=
list 双向迭代器：只支持== !=，禁止<比较。迭代器循环统一习惯写!= end，通用性最强。
*/