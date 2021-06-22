#include <iostream>
//#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int num;
    while (cin >> num)
    {
        v.push_back(num);
    }
    cout << "输出相邻元素的和：" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] + v[i + 1] << " ";
    }
    cout << endl;

    cout << "输出首尾元素的和：" << endl;
    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        cout << v[i] + v[j] << " ";
    }
    cout << endl;
    
    return 0;
}