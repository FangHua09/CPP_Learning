/*
 找出错误，说明原因并修改

(a)
int f() {
    string s;
    //...
    return s;
}
错误：函数返回类型是int，但是 return 返回string s，返回值类型不匹配。修改：把返回类型改成string
string f() {
    string s;
    //...
    return s;
}

(b)
f2(int i) {   }
错误：函数缺少返回类型。C++ 函数必须显式指定返回类型，不能省略。修改：补充返回类型（根据业务，示例用 void）
void f2(int i) {   }

(c)
int calc(int v1, int v1)   { }
错误：形参列表里两个形参名字完全相同v1；同一个函数形参不能重名。修改：修改为不同参数名
int calc(int v1, int v2)   { }

(d)
double square(double x) return x * x;
错误：函数体没有大括号{ }包裹函数语句。修改：加上{}
double square(double x) { return x * x; }
*/