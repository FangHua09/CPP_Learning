/*
题目描述：下列 vector 对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。

(a) vector<vector<int>> ivec;✅ 合法定义一个vector，它的每个元素类型是vector<int>；ivec为空，不含任何元素。
(b) vector<string> svec = ivec;❌ 不合法ivec是vector<vector<int>>，不能用它给vector<string>初始化；类型不匹配，不能把vector<int>赋值给string，编译报错。
(c) vector<string> svec(10, "null");✅ 合法创建含有 10 个元素 的vector<string>，每个元素都被初始化为字符串"null"。
*/