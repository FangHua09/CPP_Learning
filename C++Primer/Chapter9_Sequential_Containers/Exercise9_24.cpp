/*
题目：编写程序，分别使用at、下标运算符、front和begin提取一个 vector 中的第一个元素。在一个空 vector 上测试你的程序。

// 空vector测试
    std::vector<int> empty_vec;

    // empty_vec.at(0);       // ✖ 抛出 out_of_range 异常
    // empty_vec[0];          // ✖ 下标访问空容器，未定义行为，不会抛异常，程序崩溃
    // empty_vec.front();     // ✖ 对空容器调用front，未定义行为
    // *empty_vec.begin();    // ✖ begin等于end，解引用尾后迭代器，未定义行为
*/
