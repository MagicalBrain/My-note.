/*
* 问题：创建一个vector，用于存储不重复的单词
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using std::vector;
using std::string;
using std::set;

int main() {
    vector<string> words;
    set<string> words_set;

    string word;
    while (cin >> word)
    {
        words_set.insert(word);
        if (words.size() > 1) {
            bool flag_find = false;
            for (auto i : words)
                if (i == word)
                    flag_find = true;
            
            if (!flag_find)
                words.push_back(word);
        }
        else words.push_back(word);
    }

    for (auto i : words)
        cout << i << " ";
    cout << endl;
    
    //words_set.insert(words.cbegin(), words.cend());
    for (auto i : words_set)
        cout << i << " ";
    cout << endl;
    
    return 0;
}