/*
题目：希望定义 StrBlob 的值版本，继续使用 shared_ptr；StrBlobPtr 仍可以使用 weak_ptr。修改后的类需要拷贝构造、拷贝赋值；不需要析构函数。解释拷贝构造、拷贝赋值需要做什么，为什么不需要析构。
拷贝构造函数

StrBlob 成员：shared_ptr<vector<string>> data;
值语义：不能共享同一个 vector。拷贝构造时，新建一个 vector，把原对象*data里面全部元素复制进去；再用make_shared包装这个新 vector，赋值给当前对象data。
拷贝完成后新旧 StrBlob 各自持有独立 vector，修改一方不影响另一方。
拷贝赋值运算符
先创建右侧对象底层 vector 的完整副本；把副本包装为 shared_ptr，赋值给当前对象data。
原来的data会自动递减引用计数；引用计数为 0 时 shared_ptr 自动释放旧 vector。

为什么不需要自定义析构函数
StrBlob 唯一成员是shared_ptr<vector<string>> data。
合成析构会销毁成员data；shared_ptr自带析构逻辑，自动递减引用计数，计数为 0 自动释放底层 vector。
没有裸指针，不需要手动 delete，所以不用写析构。
*/
