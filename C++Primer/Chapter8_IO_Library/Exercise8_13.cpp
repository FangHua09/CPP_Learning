// **题目描述**：重写本节的电话号码程序，从一个命名文件而非 ifs 读取数据。
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

    // 创建一个文件输入流，用作读取文本
    ifstream ifs(R"(C:\Users\13075\CLionProjects\C++Learning\C++Primer\Chapter8_IO_Library\Exercise8_13.txt)");
    // 确认读取成功
    if(!ifs) cout << "读取失败" << '\n';


    while (getline(ifs, line))
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
