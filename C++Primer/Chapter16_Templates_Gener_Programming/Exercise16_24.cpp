/*
 *练习 16.24：Blob 模板添加接收两个迭代器的构造函数
 Blob 模板（教材模板类，底层用 shared_ptr 保存 vector），新增迭代器版本构造函数。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <numeric>
#include <bitset>
#include <climits>
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

template <typename It>
class Blob
{
public:
    using size_type = size_t;
    Blob() : data(make_shared<vector<T>>(data)) {}

    template <typename It>
    Blob(It beg, It end);

private:
    shared_ptr<vector<T>> data;
};
template <typename T>
template <typename It>
Blob<T>::Blob(It beg, It end)
{
    data = make_shared<vector<T>>(vector(beg, end));
}
/*
要点说明
构造函数本身是内部模板，模板参数Iter代表任意迭代器类型；
直接用beg, end构造内部vector<T>；
兼容容器迭代器，例如：
*/