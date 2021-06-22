#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
using std::vector;
using std::string;

int main() {
    vector<string> text;
    string str;
    while (cin >> str) {
        text.push_back(str);
    }
    for (auto i = text.begin(); i != text.end() && !i->empty(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            *j = toupper(*j);
        }
        
    }
    cout << *text.begin() << endl;
    return 0;
}