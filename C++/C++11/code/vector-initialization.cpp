#include <iostream>
#include <string>
#include <vector>

//using namespace std;
using std::vector;
using std::string;

int main() {
    //练习 3.12
    vector<vector<int>> ivec1;
    vector<string> ivec2;
    vector<string> svec1 = ivec2;
    vector<string> svec2(10,"null");
    //练习 3.13
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    return 0;
}