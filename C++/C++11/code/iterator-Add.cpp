#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int n;
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    vector<int>::iterator it = v.begin() + v.end() - 1;
    return 0;
}