/*
 *在每个构造函数内添加cout打印语句，用来验证 15.34 (a)(b)。示例：
 cpp
 WordQuery(const string& s) : query_word(s) {
     cout << "【构造 WordQuery】" << s << endl;
 }
 AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&"){
     cout << "【构造 AndQuery】" << endl;
 }
 运行表达式Query("fiery") & Query("bird") | Query("wind");，控制台输出构造函数调用顺序，验证 15.34 (a)；
 cout << q时会打印 rep 调用过程，验证 (b)。
 */
