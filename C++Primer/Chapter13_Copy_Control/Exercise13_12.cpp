/*
问题：下面代码片段中会发生几次析构函数调用？
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
    
✅ 一共 3 次析构调用函数执行结束，局部对象全部销毁，顺序：
item2 局部对象销毁
item1 局部对象销毁
形参 accum（值传递拷贝出来的副本）销毁
trans 是指针，不会销毁指针指向的对象；只是指针变量本身销毁，指针变量是内置类型，没有析构。局部对象和值传递形参在函数退出时销毁，共 3 个 Sales_data 对象 → 3 次析构。
*/
