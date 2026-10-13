/*
 *对比 可变参数模板版 errorMsg VS initializer_list 版 error_msg
 6.2.6 旧版（initializer_list）原型
 void error_msg(initializer_list<string> il)
 {
     for (auto &e : il) cout << e << " ";
 }
 调用方式：error_msg({"error", "val:", to_string(x)});


 ✅可变参数模板版本（16 章）
 优点
 类型不限：可以直接传任意类型（int, double, string, 指针），自动调用debug_rep转换；不需要手动把所有参数转成string。
 不用大括号{}包裹，调用更自然：errorMsg(10, "abc", p)。
 编译期展开，没有运行时数组开销；类型安全更强。
 缺点
 模板会为每一组不同实参类型实例化一份函数代码，会带来代码膨胀（code bloat）。
 所有代码必须放在头文件，不能分离声明定义。
 编译时间更长；错误提示晦涩难懂。

 ✅initializer_list 版本（6 章）
 优点
 普通函数，只生成一份函数实例，不会代码膨胀。
 可以把实现放 cpp 源文件，头文件只放声明。
 编译速度快，报错信息简单。
 缺点
 所有元素必须是相同类型（string），调用时必须手动将所有参数转为 string，写法麻烦：error_msg({"a", to_string(b)})。
 调用必须带上大括号{}，语法累赘。
 运行时会创建initializer_list数组，有少量运行时开销。
 */
