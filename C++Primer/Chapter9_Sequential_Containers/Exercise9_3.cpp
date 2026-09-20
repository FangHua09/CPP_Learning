/*
题目描述：构成迭代器范围的迭代器有何限制？

解答迭代器范围是 [begin, end)，左闭右开区间，需要满足下面限制：
begin 和 end 必须指向同一个容器。
end 不能在 begin 的前面；begin到end，通过反复自增begin，可以到达 end。
end可以等于begin，代表空范围。

通俗：begin 指向首元素，end 指向尾后位置；区间包含 begin，不包含 end。
核心要点同一容器、begin可达end，左闭右开[begin,end)。
*/