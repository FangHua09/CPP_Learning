/*
假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面循环的行为，
然后编写程序验证你的分析是否正确。
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2) // 如果是奇数
        iter = vi.insert(iter, *iter);
    ++iter;

    解答
    ⚠️ 注意代码缩进：++iter不属于 if 语句块，每次循环一定会执行。
    insert(iter, *iter)会把元素插入到iter前面，返回指向新插入元素的迭代器；
    iter被赋值为新元素迭代器；
    执行++iter，回到原来旧奇数元素的位置；
    下一轮循环又检测到该位置是奇数，再次插入，无限死循环。
*/