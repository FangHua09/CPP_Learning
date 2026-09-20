/*
重写第 1 题的程序，用 lambda 代替end_connection函数。（参见 10.3.2 节，第 346 页）
知识点
lambda 表达式作为shared_ptr的自定义删除器。
lambda 捕获参数，在资源销毁时执行清理逻辑。
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

// 模拟连接类型
struct connection
{
    std::string ip;
    int port;
    connection() = default;
    connection(const string &ip, int port) : ip(ip), port(port) {}
};

// 模拟打开链接
connection *connect(const string &ip, int port)
{
    std::cout << "打开连接 " << ip << ":" << port << "\n";
    return new connection(ip, port);
}

// 模拟关闭连接
void end_connect(connection *p)
{
    std::cout << "关闭连接 " << p->ip << ":" << p->port << "\n";
    delete p;
}

// 用shared_ptr管理connection。实现包装
/*
打开连接 127.0.0.1:8080
正在使用连接
关闭连接 127.0.0.1:8080
*/
void f(const string &ip, int port)
{
    shared_ptr<connection> p(connect(ip, port), [](connection *p) -> void
                             {
        std::cout << "关闭连接 " << p->ip << ":" << p->port << "\n";
    delete p; }); // 指定删除器
    std::cout << "正在使用连接\n";
}

int main()
{
    f("127.0.0.1", 8080);
    return 0;
}