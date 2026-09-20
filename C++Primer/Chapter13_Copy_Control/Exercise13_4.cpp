/*
找出代码里调用拷贝构造函数的位置
Point global;
Point foo_bar(Point arg)  //① 形参arg：传值，调用拷贝构造，拷贝实参
{
    Point local = arg, *heap = new Point(global); 
    //② local = arg：用arg拷贝初始化local
    //③ new Point(global)：用global拷贝初始化堆上Point对象
    *heap = local; //⚠️ 这是赋值运算符！不是拷贝构造，对象已经存在
    Point pa[ 4 ] = { local, *heap }; 
    //④ 数组pa前两个元素：用local、*heap拷贝初始化数组元素
    return *heap;  //⑤ 按值返回，拷贝*heap创建临时返回对象
}
✅ 拷贝构造调用点：
foo_bar(Point arg)：传值形参初始化 arg
Point local = arg
new Point(global)
数组pa初始化 {local, *heap} 两个元素
return *heap; 按值返回，拷贝对象
注意：*heap = local; 是赋值操作，对象 heap 已经构造完毕，调用赋值运算符，不是拷贝构造。

*/
