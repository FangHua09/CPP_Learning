/*
题目：StrBlob 需要 const 版本的 push_back 和 pop_back 吗？如果需要，添加进去。否则，解释为什么不需要。
知识点：const成员函数语义：承诺不修改对象状态；const对象不能修改封装的数据。
解答：
不需要。
push_back 和 pop_back 的作用是修改底层 vector，会改变 StrBlob 对象管理的数据。
const成员函数保证不会修改对象，因此不可能提供 const 版本的push_back/pop_back；const StrBlob对象不能调用这两个修改型成员函数。
*/

