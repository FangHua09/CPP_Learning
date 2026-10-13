/*
 *template <typename It>
 auto fcn3(It beg, It end) -> decltype(*beg + 0)
 {
     // 处理序列
     return *beg; // 返回序列中一个元素的拷贝
 }
 ✅ 函数合法
 
 1. 返回类型
 decltype(*beg + 0)
 *beg 是迭代器解引用得到的元素；
 *beg + 0：会把元素做加法运算，会去掉引用属性。
 所以返回类型是：迭代器所指元素的值类型（非引用）。
 举例：vector<int>::iterator，*beg是int&；*beg +0结果是int，返回类型int。
 
 2. 对实参（迭代器 It）的限制
 It必须是可解引用的迭代器：*beg合法；
 *beg的结果必须支持和 0 做+加法运算；
 数值类型（int、double 等）没问题；
 比如string迭代器：*beg是char，char + 0可以；
 但是：string本身、或者没有重载operator+的自定义类，就不能使用这个函数；
 beg、end必须是一对合法的迭代器，表示有效区间；
 返回语句return *beg;会拷贝元素，所以元素类型需要可拷贝。
 一句话总结：迭代器解引用出来的类型必须支持 +0。decltype(*beg+0)会剥离引用，返回值类型。
 */
