/*
如果move、set、display返回值是Screen（值返回，不是引用Screen&）会发生什么？
返回Screen，是值返回，返回临时对象拷贝，不是原对象。

执行语句：
myScreen.move(4,0).set('#').display(cout);

myScreen.move(4,0)：返回临时拷贝对象，不是 myScreen 本身；原对象 myScreen 光标不变。
接着调用.set('#')修改的是这个临时拷贝，不是 myScreen；myScreen本身不会被修改。
.display(cout)输出这个临时对象。
语句结束，临时对象销毁。
*/