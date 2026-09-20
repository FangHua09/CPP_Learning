/*
举一个形参应该是引用类型的例子；举一个不能是引用类型的例子。
✅ 应该用引用：交换函数 swap；reset 修改实参；大对象（string / 容器）传参避免拷贝开销。
 
void swap(int &a,int &b);
void printBigString(const string &s); //const引用避免拷贝
✅ 不能用引用类型：函数处理字面值、计算中间临时拷贝。
 
//值传递，需要一份独立副本，不能用引用
int fact(int n)
{
    int res=1;
    for(int i=2;i<=n;i++) res *=i;
    return res;
}
调用fact(5)传入字面值5；如果形参写成int &n，编译报错，右值不能绑定普通非 const 引用。
补充：const T&可以接收右值；普通T&不能接收字面值临时量。
*/