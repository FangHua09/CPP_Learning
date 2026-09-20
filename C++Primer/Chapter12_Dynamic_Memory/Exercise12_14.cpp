/*
编写你自己版本的用shared_ptr管理connection的函数。
背景：书中connection代表网络连接，end_connection是关闭连接的函数，shared_ptr支持自定义删除器，当引用计数归 0 时调用删除器释放资源。

知识点
shared_ptr自定义删除器：可以传入一个可调用对象，当shared_ptr销毁时执行，而不是默认delete。
管理非堆内存资源（socket / 连接句柄），不能用普通 delete，必须用业务函数释放。
传入删除器的语法：shared_ptr<T> p(ptr, deleter);
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
struct connection {
    std::string ip;
    int port;
    connection() = default;
    connection(const string& ip, int port) : ip(ip), port(port){}
};

// 模拟打开链接
connection* connect(const string& ip, int port){
     std::cout << "打开连接 " << ip << ":" << port << "\n";
     return new connection(ip, port);
}

// 模拟关闭连接
void end_connect(connection *p) {
    std::cout << "关闭连接 " << p->ip << ":" << p->port << "\n";
    delete p;
}


// 用shared_ptr管理connection。实现包装
/*
打开连接 127.0.0.1:8080
正在使用连接
关闭连接 127.0.0.1:8080
*/
void f(const string& ip, int port){
    shared_ptr<connection>p(connect(ip, port), end_connect); // 指定删除器
    std::cout << "正在使用连接\n";
}

int main()
{
    f("127.0.0.1", 8080);
    return 0;
}