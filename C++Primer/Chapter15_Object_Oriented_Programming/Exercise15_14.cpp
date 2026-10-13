/*
 *base bobj;        base *bp1 = &bobj;     base &br1 = bobj;
 derived dobj;     base *bp2 = &dobj;     base &br2 = dobj;
 规则：
 非虚函数：静态绑定（看声明类型）
 virtual 函数：动态绑定（看实际对象类型）
 name()不是虚函数；print()是虚函数。
 
 (a) bobj.print();对象是 base，调用base::print
 (b) dobj.print();对象是 derived，调用derived::print
 (c) bp1->name();bp1 静态类型base*，name 非虚 → base::name
 (d) bp2->name();bp2 静态类型base*，name 非虚 → base::name
 (e) br1.print();br1 绑定 base 对象，虚函数 → base::print
 (f) br2.print();br2 绑定 derived 对象，虚函数 → derived::print
 */
