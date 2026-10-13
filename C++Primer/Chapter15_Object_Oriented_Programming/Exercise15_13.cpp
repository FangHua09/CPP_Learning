/*
 *class base {
 public:
     string name() { return basename; }
     virtual void print(ostream &os) { os << basename; }
 private:
     string basename;
 };
 
 class derived : public base {
 public:
     void print(ostream &os) { print(os); os << " " << i; } // 问题在这里！
 private:
     int i;
 };
 问题分析
 derived::print里面写print(os);，无限递归调用自身，不是调用基类版本！print(os)在 derived 类作用域，优先匹配当前类的 print，造成死递归。
 */
