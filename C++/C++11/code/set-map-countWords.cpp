/*
* 问题；如何忽略大小写？
* 解决方法：全转为小写即可
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;
using std::string;
using std::map;
using std::set;

int main() {
    //统计输入中每个单词出现的次数
    map<string, int> word_count; // string到sizet的空map
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"}; 
    string word;
    while (cin >> word)
    {
        for (auto &i : word)
            i = tolower(i);
        
        //只统计不在exclude中的单词
        if (exclude.find(word) == exclude.end())
            ++word_count[word]; //获取并递增word的计数器
    }
    for (auto i : word_count)
    {
        cout << i.first << " occurs " << i.second 
            << (i.second > 1 ? " times." : " time.") << endl;
    }
    
    return 0;
}
