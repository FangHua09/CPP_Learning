/*
题目：假定`v`是一个`vector<double>`，那么调用`accumulate(v.cbegin(), v.cend(), 0)`有何错误？

✅ 错误分析：
accumulate的返回类型由第三个参数（初始值）的类型决定。这里初始值0是int类型。
累加时，vector里的double元素会被强制转换成int再参与计算，小数部分会被截断，得到错误结果。

✅ 正确写法：
accumulate(v.cbegin(), v.cend(), 0.0);
0.0是double类型，累加过程保留小数。
*/