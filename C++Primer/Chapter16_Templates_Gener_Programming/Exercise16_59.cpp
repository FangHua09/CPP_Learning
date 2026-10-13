/*
 *练习 16.59：假定 s 是 string，解释 svec.emplace_back(s);
 string s = "hello";
 svec.emplace_back(s);
 s是左值。模板推导时，Args被推导为string&；
 forward把s仍然转发为左值引用；
 调用string的拷贝构造函数，在容器内存中就地拷贝构造一个新的 string；
 等价于：svec.emplace_back(string(s));，但直接使用左值 s，触发拷贝构造。
 对比：svec.emplace_back(std::move(s))，会转发成右值，调用 string 移动构造。
 一句话：emplace_back(s)传入左值 s，就地调用 string 拷贝构造函数创建新元素。
 */
