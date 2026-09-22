/*

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

class Folder;
class Message
{
public:
    Message(const string& s = ""): contents(s){}

    // 拷贝构造
    Message(const Message&);
    //拷贝赋值
    Message& operator= (const Message&);
    //析构
    ~Message();

    //save, remove
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;
    set<Folder*> folders;
    // 拷贝构造 拷贝赋值 析构所用到的工具函数
    void add_to_folders(const Message&);
    void remove_from_folders();
};

