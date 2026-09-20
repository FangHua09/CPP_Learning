/*
本节（9.3.2）第一个程序原文（C++ Primer）：
auto val = *c.begin(), val2 = c.front();
auto last = c.end();
auto val3 = *(--last);
auto val4 = c.back();

val：*c.begin() 取首元素
val2：c.front() 取首元素
val3：*(--last)，end()是尾后迭代器，--last指向最后一个元素
val4：c.back() 取最后一个元素

题目条件：c.size() == 1，容器只有 1 个元素。此时首元素 = 尾元素，val、val2、val3、val4 全部等于容器仅有的那一个元素值。
举例：c={10}，则四个变量全部为10。
说明：size=1 时，begin () 指向唯一元素；end () 向前递减一步也指向这个唯一元素，front ()、back () 也返回该元素。
*/
