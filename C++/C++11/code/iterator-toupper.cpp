#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //使用迭代器来将字符串里的第一个单词转为大写
    string s;
    cin >> s;
    for (auto i = s.begin(); i != s.end() && !isspace(*i); i++)
    {
        *i = toupper(*i);
    }
    cout << s << endl;
    return 0;
}