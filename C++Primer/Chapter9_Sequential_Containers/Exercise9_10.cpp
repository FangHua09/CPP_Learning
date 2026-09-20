/*
题目描述：下面 4 个对象分别是什么类型？
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();

解答
it1：vector<int>::iteratorv1是非 const 容器，begin()返回普通迭代器，可读可写。
it2：vector<int>::const_iteratorv2是 const 容器，begin()返回常量迭代器，只能读，不能修改。
it3：vector<int>::const_iteratorcbegin()强制返回常量迭代器。
it4：vector<int>::const_iteratorv2是 const，cbegin()依旧返回常量迭代器。
*/