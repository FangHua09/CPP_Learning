/*
描述 map 和 vector 的不同。
知识点
vector：顺序容器，连续内存，按位置下标访问；map：关联容器，红黑树实现，按键 key查找。

解答
存储结构：vector 是顺序容器，元素在连续内存空间，按顺序存放；map 是关联容器（红黑树），存储 pair<const key, value>，元素按键有序排列，内存不连续。
索引方式：vector 使用位置下标（0 开始整数索引）访问；map 使用键 key查找，下标不是位置。
查找效率：vector 查找需要遍历 O (n)；map 根据 key 查找 O (log n)。
元素类型：vector 只存单一类型元素；map 存键值对，key 不可修改。
插入：vector 中间插入会移动后面元素；map 插入只调整树节点，不移动已有元素
*/
