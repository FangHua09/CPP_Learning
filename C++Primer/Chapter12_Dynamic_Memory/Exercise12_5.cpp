/*
题目：我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。
知识点：构造函数explicit关键字；隐式类型转换；initializer_list构造函数。

解答：
构造函数：StrBlob(initializer_list<string> il); 没有加explicit
✅ 优点：允许隐式转换。函数接收const StrBlob&参数时，可以直接传入花括号列表{"a","b"}，编译器自动用 initializer_list 构造临时 StrBlob，代码书写简洁。
❌ 缺点：会产生意料之外的隐式转换。只要函数参数是 StrBlob，传入花括号初始化列表就会隐式构造临时对象，容易引入隐蔽 bug，降低代码可读性。
如果添加explicit，会禁止隐式转换，只能显式构造对象。
*/

