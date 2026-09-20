/*
如果把 Screen 类里面 typedef string::size_type pos;（using pos = string::size_type;）放到类定义的最后一行会发生什么？
class Screen {
public:
    // ……其他成员函数，用到 pos
private:
    pos height = 0, width = 0;  // 使用 pos
    std::string contents;
public:
    typedef std::string::size_type pos; // 移到类末尾
};


结果：编译报错。
C++ 类内部，名字必须先声明，后使用。pos 用来定义成员变量 height、width，但是 typedef 写在类的最后，编译器读到pos height的时候，还没有见过pos的定义，不知道pos是什么类型。
类的作用域是整个类，但是声明顺序依然有效，不能 “先使用后定义”。类型别名必须在第一次使用该别名之前完成定义。
✅正确：typedef 要放在类中第一次使用pos之前。
*/