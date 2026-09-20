/*
题目描述：在 100 页的二分搜索程序中，为什么用的是 mid = beg + (end ‑ beg) / 2;，而非 mid = (beg + end) / 2;?

两点原因：
vector 迭代器不支持加法运算 beg + endbeg和end都是迭代器。迭代器可以做减法 end‑beg，得到两个迭代器之间的距离（difference_type 类型）；
但是两个迭代器不能直接相加，beg + end语法不合法，编译报错。
beg + (end‑beg)/2：end‑beg算出距离，距离除以 2，再加到起始迭代器beg上，得到中间位置迭代器mid，语法合法。
补充：普通整数写mid=(left+right)/2会有溢出风险；但这里首先是语法层面：迭代器没有+运算符。
*/