// 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
/*
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);

(a) calc(23.4, 55.1);：不合法。calc只接受 1 个 double 实参，传入 2 个实参，参数数量不匹配。
(b) count("abcda", 'a');：合法。const string&常量引用可以绑定字符串字面值临时对象。
(c) calc(66);：合法。int 类型 66 隐式转换为 double。
(d) sum(vec.begin(), vec.end(), 3.8);：合法。double 3.8 隐式转换 int，截断为 3。
*/