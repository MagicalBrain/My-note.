#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

static int cnt = 1;

bool vector_check(vector<int> v) {
    cout << "cnt: " << cnt++ << endl;
    if (v.size() < 1)
        return false;
    else {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return true;
}

bool vector_check(vector<string> v) {
    cout << "cnt: " << cnt++ << endl;
    if (v.size() < 1)
        return false;
    else {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return true;
}

int main() {
    //练习 3.13
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    //练习 3.16
    vector_check(v1);
    vector_check(v2);
    vector_check(v3);
    vector_check(v4);
    vector_check(v5);
    vector_check(v6);
    vector_check(v7);
    return 0;
}