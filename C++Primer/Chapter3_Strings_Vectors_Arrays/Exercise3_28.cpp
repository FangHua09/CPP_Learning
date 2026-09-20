/*
下列数组中元素的值是什么？
string sa[10];
int ia[10];
int main() {
    string sa2[10];
    int ia2[10];
}

string sa[10]; 全局数组string默认构造，10 个空字符串。
int ia[10]; 全局数组全局内置类型会自动初始化为 10 个 0。
string sa2[10]; main 内部局部数组string对象，全部初始化为空字符串。
int ia2[10]; main 内部局部数组局部内置类型不会自动初始化；元素是未定义的随机垃圾值。

总结：
全局：内置 int 初始化为 0；类类型调用默认构造。
局部栈上数组：类类型 (string) 调用默认构造；内置 int 不初始化，值随机。
*/