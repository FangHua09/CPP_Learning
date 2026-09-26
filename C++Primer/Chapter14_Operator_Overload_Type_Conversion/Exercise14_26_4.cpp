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

class String
{
public:
    // ...原有代码
    char &operator[](size_t i);
    const char &operator[](size_t i) const;

    size_t size() const{ return end - elements; }

private:
    char *elements;
    char *end;
};

char &String::operator[](size_t i)
{
    if (i >= size())
        throw runtime_error("String下标越界");
    return elements[i];
}

const char &String::operator[](size_t i) const
{
    if (i >= size())  // 常函数只能调常函数
        throw runtime_error("const String下标越界");
    return elements[i];
}
