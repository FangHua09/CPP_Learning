/*
 *练习 16.27：分析每一行，判断是否实例化 Stack<T>
 template <typename T> class Stack {};
 void f1(Stack<char>);                    // (a)
 class Exercise {
     Stack<double> &rsd;                  // (b)
     Stack<int> si;                       // (c)
 };
 int main() {
     Stack<char> *sc;                     // (d)
     f1(*sc);                             // (e)
     int iObj = sizeof(Stack<string>);    // (f)
 }

 核心规则：仅仅声明指针 / 引用，不会实例化类模板；创建对象（定义实体）才会实例化类。
 (a) void f1(Stack<char>);只是函数声明，参数是Stack<char>类型。这里只用到类型名字，不实例化 Stack<char>。没有创建对象。
 (b) Stack<double> &rsd;引用只是别名定义，引用本身不是对象。不实例化 Stack<double>。引用不需要分配内存，不需要完整类定义。
 (c) Stack<int> si;定义了Stack<int>类型的对象 si。需要完整类定义，实例化 Stack<int>。
 (d) Stack<char> *sc;只是指针声明。指针只需要类的前置声明，不需要完整类定义，不实例化 Stack<char>。
 (e) f1(*sc);解引用指针*sc得到Stack<char>对象，函数传参使用这个对象，实例化 Stack<char>。
 (f) sizeof(Stack<string>)sizeof需要知道Stack<string>的大小，必须要有完整类定义，实例化 Stack<string>。
 */
