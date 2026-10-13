/*
 *不能显式实例化 vector<NoDefault>
 原理（对应书上原文）
 类模板的显式实例化定义 template class vector<NoDefault>; 会实例化该模板所有成员函数，不是只实例化被用到的成员。
 vector<T> 的成员里面包含它自己的默认构造函数：vector::vector ()。 这个默认构造函数的语义是：创建空 vector，但是当 T=NoDefault，vector<NoDefault> 的默认构造函数的实现代码里，会假设 NoDefault 是可以默认构造的。
 哪怕你自己代码里永远不去调用 vector<NoDefault> 的默认构造函数！ 只要写了 template class vector<NoDefault>;，编译器就会强行实例全部成员，包括 vector<NoDefault>默认构造函数。 实例这个默认构造函数的时候，它会尝试实例化 NoDefault 的默认构造，而 NoDefault 没有默认构造函数，直接编译报错。
 区分两个容易混淆的情况
 ✅ 隐式实例化：你只写 vector<NoDefault> v (10, ndObj);（调用带参数构造，不调用 vector 默认构造） 此时隐式实例化只会实例化被调用的成员，不会实例 vector 默认构造，可以编译通过。
 ❌ 显式实例化定义：template class vector<NoDefault>; 强制实例全部成员，包含 vector 默认构造函数 → 触发对 NoDefault 默认构造的查找，找不到，编译失败。
 */
