/*
(a)
原代码：
vector<int> vec; list<int> lst; int i;
while (cin >> i)
    lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
❌ 错误：vec是空容器，vec.begin()没有指向有效元素。copy要求目标迭代器指向已经存在的元素（用来覆盖），这里直接写入会越界。
✅ 修改：使用back_inserter(vec)插入迭代器，自动调用push_back添加元素：
copy(lst.cbegin(), lst.cend(), back_inserter(vec));

(b)
原代码：
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);
❌ 错误：reserve(10)只预分配内存，不会创建元素，vec.size()依旧是 0。fill_n尝试写入 10 个不存在的元素，造成越界。
✅ 修改方案 1：用resize(10)创建 10 个元素
vec.resize(10);
fill_n(vec.begin(), 10, 0);
✅ 修改方案 2：使用back_inserter
fill_n(back_inserter(vec), 10, 0);
*/