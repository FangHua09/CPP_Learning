/*
 *代码验证
 */
#include <iostream>
using namespace std;
class Base {
public:
    int pub_mem;
protected:
    int prot_mem;
private:
    int pri_mem;
};

class Pub_Derv : public Base {
public:
    void memfcn(Base &b) { b = *this; } // ok
};
class Priv_Derv : private Base {
public:
    void memfcn(Base &b) { b = *this; } // ok
};
class Prot_Derv : protected Base {
public:
    void memfcn(Base &b) { b = *this; } // ok
};

class Derived_from_Public : public Pub_Derv {
public:
    void memfcn(Base &b) { b = *this; } // ok
};
class Derived_from_Private : public Priv_Derv {
public:
    // void memfcn(Base &b) { b = *this; } // 编译报错！
};
class Derived_from_Protected : public Prot_Derv {
public:
    void memfcn(Base &b) { b = *this; } // ok
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;    // ok
    //p = &d2;        // error
    //p = &d3;        // error
    p = &dd1;         // ok
    //p = &dd2;       // error
    //p = &dd3;       // error
    return 0;
}
