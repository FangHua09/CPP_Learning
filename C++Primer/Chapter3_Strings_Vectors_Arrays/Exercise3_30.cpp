/*
找出代码索引错误
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
/错误：数组下标越界数组ia大小为 10，合法下标：0 ~ 9。循环ix从 1 开始，循环条件ix <= 10，当ix=10时执行ia[10]=10，访问不存在元素，未定义行为。
修正：
for (size_t ix = 0; ix < array_size; ++ix)
    ia[ix] = ix;

*/