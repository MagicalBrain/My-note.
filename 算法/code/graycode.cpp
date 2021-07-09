/*
* 实现格雷码
*/
#include <iostream>
#include <string>

using namespace std;
using std::string;

int main() {
    string in;
    string out;
    int illegal = 0;

    cout << "请输入一个二进制数：" << endl;
    cin >> in;
    if (in.empty()) {
        cout << "输入非法！" << endl;
        return 0;
    }
    for (auto i : in)
    {
        if (i != '0' && i != '1')
            illegal = 1;
    }
    if (illegal)
    {
        cout << "输入的不是二进制数！" << endl;
        return 0;
    }
    
    for (int i = 0; i < in.size(); i++)
    {
        if (i == 0)
            out.push_back(in[i]);
        else
            out.push_back( (in[i] + in[i - 1]) % 2 + '0');
    }
    
    cout << "转换的格雷码为：" << out << endl;
    return 0;
}