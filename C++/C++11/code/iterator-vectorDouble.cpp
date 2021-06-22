#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int num;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (auto i = v.begin(); i != v.end(); i++)
    {
        *i = *i * 2;
    }
    
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;
    
    return 0;
}