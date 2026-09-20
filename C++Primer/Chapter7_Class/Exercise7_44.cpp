/*
vector<NoDefault> vec(10);
不合法。vector<T> vec(n)会创建n个元素，需要使用T的默认构造函数初始化每一个元素。NoDefault没有默认构造函数，所以编译失败。
*/