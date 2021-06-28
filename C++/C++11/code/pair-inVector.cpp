#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
using std::vector;
using std::string;

int main() {
    string str;
    int num;
    vector<pair<string, int> > v;

    while (cin >> str >> num)
        v.push_back(make_pair(str, num));
    
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    //cout << endl;  
    
    return 0;
}