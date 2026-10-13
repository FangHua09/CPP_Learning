/*
 *问题 1：为什么为 Disc_quote 定义默认构造函数？
 因为派生类 Bulk_quote 声明了自己的默认构造函数 Bulk_quote() = default;。当调用 Bulk_quote 的默认构造函数时，编译器会自动调用它的直接基类 Disc_quote 的默认构造函数。如果没有 Disc_quote 的默认构造，Bulk_quote 的默认构造就会编译失败。
 注意：Disc_quote 有一个带 4 个形参的构造函数。一旦类中定义了非默认构造函数，编译器就不会再自动合成默认构造函数。所以我们必须手动写 Disc_quote() = default;，供派生类默认构造使用。
 
 问题 2：如果去掉 Disc_quote 的默认构造函数，对 Bulk_quote 的影响？
 Bulk_quote 的默认构造函数 Bulk_quote() = default; 编译报错。
 原因：执行 Bulk_quote 默认构造时，编译器尝试调用 Disc_quote 默认构造，但它不存在。
 但是：Bulk_quote 的带参构造函数不受影响，因为它在初始化列表里显式调用了 Disc_quote 的带参构造，不需要用到默认构造。
 
 简单总结：删除 Disc_quote 默认构造 → Bulk_quote 不能再使用默认构造创建对象；Bulk_quote 的带参构造仍然正常可用。
 */
