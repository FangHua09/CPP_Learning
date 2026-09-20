/*
题目描述：说明下面这个循环的含义，它对 assert 的使用合理吗？
string s;
while (cin >> s && s != sought) { } //空函数体
assert(cin);

解答
循环含义
循环不断读取输入字符串，循环体为空，只做查找消耗输入：
如果读到字符串等于sought，循环正常退出；
如果遇到 EOF 或者 IO 流错误，cin变为失败状态，循环退出。
assert 使用❌不合理
assert宏受NDEBUG控制：发布版本定义NDEBUG时，assert(cin)直接被删掉，检查完全消失。
assert设计目的：检查程序内部逻辑 bug；而cin失败（EOF）属于用户输入层面正常可能发生的情况，不是程序 bug。
正确做法：使用普通if(!cin)做运行时判断处理，不能依赖 assert。
*/