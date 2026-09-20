/*
题目描述：解释下面程序片段做了什么：
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);


解答
svec.reserve(1024)：预分配至少能存放 1024 个 string 的内存空间，capacity≥1024，size 不变，不创建元素。避免输入过程中多次内存重分配。
while(cin >> word)：循环读取标准输入单词，逐个push_back存入svec。
resize(svec.size()+svec.size()/2)：将容器元素数量扩大到原来的 1.5 倍。
如果当前 size 是 N，新 size = N + N/2。新增的元素执行值初始化（空 string）。
resize不会缩减 capacity，只会改变 size。


注意：reserve 只保证 capacity≥1024；如果读入超过 1024 个单词，vector 仍然会自动扩容。
*/