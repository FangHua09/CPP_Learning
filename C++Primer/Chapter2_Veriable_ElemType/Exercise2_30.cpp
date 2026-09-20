/*
区分顶层 const、底层 const
顶层 const：对象本身是 const，变量 / 指针本身的值不能修改。底层 const：指针所指向的对象是 const，不能通过指针修改所指对象；用于指针、引用。

const int v2 = 0;        // v2：顶层const，v2本身不能修改
int v1 = v2;             // v1：普通int，无const

int *p1 = &v1, &r1 = v1;// p1：普通int*，无const；r1普通int引用，无const

const int *p2 = &v2,     // p2：底层const，不能通过p2修改指向对象；p2自身可以改指向
*const p3 = &i,          // p3：底层const + 顶层const；指针本身不可改(顶层)，指向对象不可通过指针修改(底层)
&r2 = v2;                // r2：底层const引用，不能通过r2修改绑定对象

*/