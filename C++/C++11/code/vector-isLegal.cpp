#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> ivec;
    //ivec[0] = 42;
    ivec.push_back(42);
    for (auto i : ivec)
        cout << i << endl;
    return 0;
}