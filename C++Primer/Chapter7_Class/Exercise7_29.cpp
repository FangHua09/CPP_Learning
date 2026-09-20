// 修改函数返回`Screen`（值返回），验证上面推测。
/*
Screen move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;   // 返回拷贝，生成临时对象
}
Screen set(char ch)
{
    contents[cursor] = ch;
    return *this;
}
Screen display(ostream& os)
{
    os << contents;
    return *this;
}
运行结果：
myScreen.move(4,0).set('#').display(std::cout);输出带#（临时对象）
myScreen.display(std::cout);输出全部X；原对象没有变化。
和 7.28 推测完全一致。链式操作作用在临时副本，原始对象不受影响。

*/