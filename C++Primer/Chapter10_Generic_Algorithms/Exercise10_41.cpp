/*
四个算法的功能描述
replace(beg, end, old_val, new_val)
在区间 [beg, end) 内原地修改：把所有值等于 old_val 的元素，替换成 new_val。


replace_if(beg, end, pred, new_val)
在区间 [beg, end) 内原地修改：对每个元素调用谓词pred，把所有pred返回true的元素，替换成new_val。


replace_copy(beg, end, dest, old_val, new_val)
不修改原区间[beg, end)，把元素拷贝到以dest开头的目标区间：
遇到值等于old_val的元素时，拷贝new_val；其余元素原样拷贝。


replace_copy_if(beg, end, dest, pred, new_val)
不修改原区间[beg, end)，把元素拷贝到以dest开头的目标区间：
遇到pred返回true的元素时，拷贝new_val；其余元素原样拷贝。
*/