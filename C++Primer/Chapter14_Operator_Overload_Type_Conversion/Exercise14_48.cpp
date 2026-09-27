/*
 *7.40 的类（典型是Screen类），是否应该定义向 bool 的类型转换运算符？是否 explicit？Screen类：保存屏幕内容，有empty/ 有效状态的概念。
 结论：视语义而定，如果对象有 “有效 / 无效” 状态，可以提供；但强烈建议加 explicit。
 场景：Screen对象可以判断是否有效（比如屏幕缓冲区是否分配成功），那么转 bool 是合理的。
 风险：不加 explicit 会出现意外隐式转换。例如if(screen)没问题，但是screen + 5会把 screen 隐式转 bool，bool 提升成 int，产生诡异错误。
 因此：如果要写，必须写explicit operator bool() const;，只能用于if、while、static_cast等语境，不会被随意隐式转换。
 如果这个类没有 “有效 / 无效” 的语义，就完全不应该提供 bool 转换。
 */

