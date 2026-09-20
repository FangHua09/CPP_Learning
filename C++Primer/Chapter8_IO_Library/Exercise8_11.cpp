/*
教材原始代码：istringstream 对象定义在 while 循环内部。
//原版：record定义在循环内
std::string line;
while(getline(cin, line))
{
    std::istringstream record(line); //每次循环新建对象
    //读取数据
}
如果把record移到while 循环外面：对象只构造一次；每次循环必须调用record.str(line)把新字符串绑定到流，还要 clear 清除流错误标志，否则上一轮流置位 eof/failbit 之后后续读取直接失败。
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
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

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(int argc, char const *argv[])
{
    string line;
    vector<PersonInfo> people;
    stringstream iss(line); // 绑定line，使line成为流对象，此时绑定的是空行
    while (getline(cin, line))
    {
        PersonInfo person;
        // 读取之后需要调用.str(line)拷贝到流
        iss.str(line);
        string word;
        iss >> word;
        person.name = word;
        // 批量读取电话号码
        while (iss >> word)
        {
            person.phones.push_back(word);
        }
        // 读取完毕后添加人到容器
        people.push_back(person);
        // 读取下一条记录的时候记得刷新
        iss.clear();
    }

    for (auto &&person : people)
    {
        // 输出个人的信息
        cout << "姓名： " << person.name << ' ';
        for (auto &&phone : person.phones)
        {
            cout << "电话号码：" << phone << ' ';
        }
        cout << '\n';
    }

    /*
姓名： Zhang 电话号码：13800138000 电话号码：13900139000
姓名： Li 电话号码：13700137000
姓名： Wang 电话号码：13600136000 电话号码：13500135000

    */

    return 0;
}
