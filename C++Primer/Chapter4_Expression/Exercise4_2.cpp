/*
. 成员访问运算符优先级高于 *解引用。
(a) *vec.begin()
原运算顺序：先执行vec.begin()，再对返回值解引用。加括号保持原有组合顺序：

*(vec.begin())
❗不是 (*vec).begin()，(*vec).begin()含义完全不同。


(b) *vec.begin() + 1
优先级：. > * > +原顺序：先vec.begin() → 解引用 → 结果+1加括号：

*(vec.begin()) + 1
小结：
*vec.begin()等价于*(vec.begin())
千万不要写成(*vec.begin()+1)，语义不变，但必须体现.优先级高于*。

*/