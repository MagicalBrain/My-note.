#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    //vector<int> v;
    vector<string> v;
    //int num;
    string num;

    while (cin >> num)  //注意：在键盘上输入EOF文件终止符才会终止输入
    {
        v.push_back(num);
    }
    cout << endl;   //这一行为啥没执行？
    
    //这是一种传统的输出vector元素的for语句
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    //使用范围for语句来输出vecoter里的元素，注意这是c++11标准里才有的写法，可能会报错或者有警告
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}