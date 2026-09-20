/*
(a)
while (string::iterator iter != s.end()) { }
问题：iter 在while条件里被使用，但没有定义。string::iterator iter不能写在while()括号内部这种写法；这个迭代器变量不存在，编译报错。
含义本意：想用迭代器遍历字符串s，判断迭代器是否到达尾后迭代器。
修改版本：把迭代器定义放到循环外面
string::iterator iter = s.begin();
while (iter != s.end()) {
    // ...
    ++iter;
}
也可以改用for循环（更推荐）
for(string::iterator iter = s.begin(); iter != s.end(); ++iter){
    // ...
}


(b)
while (bool status = find(word)) {  }
if (!status) {  }
问题：变量作用域错误bool status是在while循环的条件部分定义，它的作用域只属于 while 循环内部。while结束之后，status变量就销毁了。后面的if (!status)访问不到 status，直接编译报错。
本意：调用find(word)得到布尔状态，循环；循环结束后根据 status 判断结果。
修改：把 status 定义移到 while 外面
bool status;
while (status = find(word)) {
    // ...
}
if (!status) {
    // ...
}
*/