/*
为什么拷贝并交换版本不理想
拷贝交换版：HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
不管传入左值还是右值，都会先构造一个 rhs 临时对象：
左值：拷贝构造 rhs；
右值：移动构造 rhs；
然后 swap。
缺点：不管移动还是拷贝场景，都必须创建临时对象。纯移动场景下，完全没必要创建临时对象，浪费开销。
*/

