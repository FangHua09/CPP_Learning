/*
 *修改Blob模板，把std::shared_ptr替换为我们手写的SharedPtr<vector<T>>
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

template <typename T>
class Blob
{
public:
    using size_type = size_t;
    Blob() : data(SharedPtr<vector<T>>(new vector<T>)) {}
    template <typename Iter>
    Blob(Iter beg, Iter end) : data(SharedPtr<vector<T>>(new vector<T>(beg, end))) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &val) { data->push_back(val); }
    void pop_back() { data->pop_back(); }
    T &back() { return data->back(); }
    T &operator[](size_t idx) { return (*data)[idx]; }

private:
    SharedPtr<vector<T>> data; // 替换为手写SharedPtr
};
