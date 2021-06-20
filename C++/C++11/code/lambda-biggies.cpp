/*
* 10.16 练习
*/
#include <iostream>
#include <vector>
#include <string>

void biggies (
    vector<string> &words,
    vector<string>::size_type sz    //这是一个unsigned类型用于存储vector容器最大长度
    )
{
    elimDups(words) ; //将words按字典序排序,删除重复单词
    //按长度排序,长度相同的单词维持字典序
    stable_sort (
        words.begin(), words.end (),
        [] (const string &a, const string &b)
            return a.size() <b.size();}
    );
    //find_if是一个标准库算法
    //获取一个迭代器,指向第一个满足size ()>= sz的元素
    auto wc = find_if(
        words.begin(), words.end (),
        [sz] (const string &a)
            { return a.size () >= sz; }
    );
    //计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " "<< make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    //打印长度大于等于给定值的单词,每个单词后面接一个空格
    for_each(
        wc, words.end(),
        [] (const string &s) {cout << s << "";}
    );
    cout < endl;
}

int main() {
    return 0;
}