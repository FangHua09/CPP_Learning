/*
 *template <typename T> void g(T&& val) { vector<T> v; }
 g(42)：42 是 int 右值
 T 推导为int；vector<int> v ✅合法，可以编译。
 g(i)：i 是 int 左值
 T 推导为int&；实例化得到vector<int&> v
 ❌编译错误：标准库vector的元素不能是引用类型；引用不是可拷贝对象，不能作为容器元素。
 */
