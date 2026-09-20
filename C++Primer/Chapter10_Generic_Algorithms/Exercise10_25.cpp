/*
在 10.3.2 节的练习中，编写了使用 partition 的 biggies 版本。使用 check_size 和 bind 重写此函数。
知识点
check_size 是通用的长度判断函数，通过 bind 固定长度阈值，可以替代 lambda 的捕获功能。
partition 需要一元谓词，bind 通过参数适配将二元 check_size 转换为一元可调用对象。
相比 lambda，函数 + bind 的方式更适合逻辑复用的场景。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

// 排序去重
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 简单排序
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// 挑选出长度大于等于sz的单词有多少个，并且打印没有大于的字符串
void biggies(vector<string> &words, string::size_type sz)
{
    elimDups(words); // 先去重

    //划分大于等于sz的区间（左区间） 使用bind加二元谓词函数版本
    auto end_part = partition(words.begin(), words.end(), bind(check_size, _1, sz));

    //划分大于等于sz的区间（左区间） 使用lambda值捕获
    // auto end_part = partition(words.begin(), words.end(), [sz](const string &s) -> bool
    //                           { return s.size() >= sz; });

    // 记录大于的有多少个
    auto count = end_part - words.begin();
    cout << "长度 >= " << sz << " 的单词有 " << count << " 个：" << endl;

    // 打印大于等于的sz的
    for_each(words.begin(), end_part, [](const string &s)
             { cout << s << ' '; });
}
int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "turtle"};
    biggies(words, 5);
    return 0;
}