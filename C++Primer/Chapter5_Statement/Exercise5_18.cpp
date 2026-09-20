/*
分析 do‑while 循环错误

(a)
原代码：
do
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
错误 1：do后面没有大括号{}。do之后只有第一条语句int v1,v2;属于循环体，后面cout、if不属于 do 循环体。错误 2：int v1,v2;定义在循环体内，while 条件部分访问不到，但本题 while 只用 cin，主要问题是缺少大括号。
本意：循环读取两个数字，输出求和，直到输入失败。
修正版本：
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
} while (cin);

(b)
原代码：
do {
    // ...
} while (int ival = get_response());
C++ 语法：do‑while的while()条件里面不能定义变量，while(变量定义)这种写法非法，编译报错。while(条件)只允许表达式，不能做变量定义。
本意：调用get_response()得到返回值存入 ival，以返回值作为循环条件。
修改：把变量定义放到循环体内部，循环条件直接调用函数：
do {
    int ival = get_response();
    // ...
} while (get_response());
注意：这样会调用两次get_response()。如果不想调用两次，把ival提到 do 外面：
int ival;
do {
    ival = get_response();
    // ...
} while (ival);
 
(c)
原代码：
do {
    int ival = get_response();
} while (ival);
错误：ival定义在 do 循环体{}内部，作用域仅限循环体；while 条件中访问ival，变量已经销毁，编译报错。
本意：循环获取响应，以 ival 的值作为循环继续条件。
修正：将ival定义在 do‑while 外面
int ival;
do {
    ival = get_response();
} while (ival);
*/