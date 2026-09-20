/*
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
错误原因：
初始化列表按照类中成员声明顺序初始化，不是初始化列表书写顺序！类内声明顺序：rem先声明，base后声明。初始化列表：先初始化rem，再初始化base。但是rem(base % j)，此时base还未初始化，使用未初始化变量，结果是未定义。
*/