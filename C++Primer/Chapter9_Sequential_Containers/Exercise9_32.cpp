/*
题目描述
在第 316 页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
iter = vi.insert(iter, *iter++);

解答
❌ 不合法，行为未定义。
C++ 中函数参数的求值顺序没有规定。表达式*iter++包含后置递增，有可能先执行iter++，此时解引用得到的是下一个元素的值，而不是iter原来指向的值，会造成插入错误的值。
正确写法应该拆分操作：
auto val = *iter;
iter = vi.insert(iter, val);
iter += 2;
*/