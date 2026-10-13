/*
 *调用make_shared为什么必须提供显式模板实参？如何使用？
 shared_ptr<int> p = make_shared<int>(42);
 原因：make_shared的返回值是shared_ptr<T>，模板参数 T 不出现在函数形参列表里。模板实参推断只看函数实参，编译器无法从传入的函数实参反推出T，所以必须手动写显式模板实参。
 使用方式：make_shared<T>(args)args是用来构造T对象的参数；make_shared在堆上创建T，返回shared_ptr<T>。
 一句话考点：模板参数只在返回值，不在形参，无法推断，必须显式指定。
 */
