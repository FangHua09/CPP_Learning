/*
题目描述：程序没有检查输入合法性，如果规则文件某一行只有一个关键字，后面跟空格然后直接结束，会发生什么？预测并验证。知识点：>> key读取单词，getline读取剩余一行；空 value 判断。解答代码：
while (map_file >> key && getline(map_file, value))
{
    if (value.size() > 1)
        trans_map[key] = value.substr(1);
    else
        throw runtime_error("no rule for " + key);
}

当一行：hello （hello + 空格，行结束）
>> key读到hello；
getline读取该行剩下内容，得到" "（一个空格）；
value.size()等于 1，条件value.size()>1不成立；
抛出异常 runtime_error("no rule for hello")。
原因：value 是单个空格，substr(1)会得到空字符串，程序认为是无效规则，抛出异常终止。
*/
