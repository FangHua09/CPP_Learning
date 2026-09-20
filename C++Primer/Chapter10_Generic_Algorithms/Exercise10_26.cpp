/*解释三种插入迭代器的不同之处。

知识点
插入迭代器（inserter iterator）是输出迭代器适配器，给容器赋值时，不是覆盖元素，而是向容器中插入元素。三种分别是：back_inserter、front_inserter、inserter。

解答
back_inserter(c)
创建尾插迭代器，调用 c.push_back(val)；只能用于支持 push_back 的容器：vector、deque、list、string。每次插入到容器末尾。
front_inserter(c)
创建头插迭代器，调用 c.push_front(val)；只能用于支持 push_front 的容器：deque、list、forward_list。每次插入到容器头部，新元素排在最前面，会反转序列。
inserter(c, iter)
通用插入迭代器，调用 c.insert(iter, val)；所有支持 insert 的容器都能用。在迭代器iter之前插入新元素。iter只是插入位置，插入后迭代器本身不会失效。

*/