/*
题目描述：下面的程序合法吗？如果不合法，你准备如何修改？

vector<int> ivec;
ivec[0] = 42;
❌ 不合法ivec是空 vector，size 为 0。下标ivec[0]访问不存在的元素，属于未定义行为，不能用下标添加元素。
✅ 修改方案：使用push_back添加元素

vector<int> ivec;
ivec.push_back(42);
重点：vector 下标只能访问已经存在的元素，不能用来新增元素
*/