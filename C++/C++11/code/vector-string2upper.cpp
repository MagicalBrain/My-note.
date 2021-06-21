#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
using std::vector;
using std::string;

int main() {
    string in;
    vector<string> v;
    while (cin >> in)
    {
        v.push_back(in);
    }

    for (auto i : v) {
        for (auto &c : i) {
            c = toupper(c);
        }
        cout << i << endl;
    }
    
    return 0;
}