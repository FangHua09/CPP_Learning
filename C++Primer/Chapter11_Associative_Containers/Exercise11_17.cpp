/*
c 是`multiset<string>`，v 是`vector<string>`，判断下面 copy 是否合法：

copy(v.begin(), v.end(), inserter(c, c.end()));   // 1
copy(v.begin(), v.end(), back_inserter(c));        // 2
copy(c.begin(), c.end(), inserter(v, v.end()));   // 3
copy(c.begin(), c.end(), back_inserter(v));        // 4

✅ 合法：inserter 可以向 multiset 插入元素。multiset 支持insert。
❌ 非法：back_inserter 调用push_back()，multiset没有push_back成员函数。
✅ 合法：inserter向 vector 指定位置插入元素。vector 支持 insert。
✅ 合法：back_inserter调用push_back()，vector 有 push_back。
*/
