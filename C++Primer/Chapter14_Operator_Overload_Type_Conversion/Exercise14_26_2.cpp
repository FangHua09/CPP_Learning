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

class StrBlobPtr
{
public:
    // ...原有代码
    string &operator[](size_t offset);
    const string &operator[](size_t offset) const;

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
};

string &StrBlobPtr::operator[](size_t offset)
{
    auto p = check(curr + offset, "越界");
    return (*p)[curr + offset];
}

const string &StrBlobPtr::operator[](size_t offset) const
{
    auto p = check(curr + offset, "越界");
    return (*p)[curr + offset];
}
