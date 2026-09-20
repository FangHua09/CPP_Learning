/*
map<string, size_t> word_count; string word;

while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
解释
word_count.insert({word,0})：尝试插入pair(word,0)。
如果word不在 map 中：插入成功，新元素值为 0，返回迭代器指向新元素 + true。
如果word已存在：插入失败，返回已有元素的迭代器 + false。
.first拿到返回 pair 里的迭代器。
->second取计数值，++计数 + 1。
功能：统计单词出现次数，等价于 word_count[word]++。
*/
