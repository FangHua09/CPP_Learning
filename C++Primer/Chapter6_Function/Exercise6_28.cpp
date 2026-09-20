/*
题目描述：在 error_msg 函数的第二个版本中包含 ErrCode 类型的参数，其中循环内的 elem 是什么类型？
书中函数原型：
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << endl;
    for (const auto &elem : il)
        cerr << elem << endl;
}

il的类型是initializer_list<string>，列表内部元素类型为string；const auto &elem，auto 推导得到 **string**，所以elem的类型是 const string &。
*/