#include <stdio.h>

#include <iostream>
#include <string>

#include <sstream>

using namespace std;

using std::stringstream;
using std::string;

void test4snprintf(string input) {
    // 准备数据
    //string haha("haha");
    int num = 3;
    // 准备格式
    string fmt("%s%d");
    char targetString[1024];
    // 格式化，并获取最终需要的字符串
    int realLen = snprintf( targetString, 
						sizeof(targetString), 
						fmt.c_str(), 
						input.c_str(), 
						num );
    cout << targetString << endl;
}

void test4sstream(string input) {
    // 准备数据
    //string haha("haha");
    int num = 3;
    // 准备根据格式造字符串流
    stringstream fmt;                       /* 或者使用 ostringstream */
    // 造字符串流
    fmt << input << num;
    // 获取最终需要的字符串
    string targetString = fmt.str();
    cout << targetString << endl;
}

void test4osstream(string input) {
    int num = 3;
    // 准备根据格式造字符串流
    ostringstream fmt;
    // 造字符串流
    fmt << input << num;
    // 获取最终需要的字符串
    string targetString = fmt.str();
    cout << targetString << endl;
}

void test4boost-format() {
    
}

int main() {
    //输入字符串
    string input;
    cin >> input;
    
    //test4snprintf(input);
    //test4sstream(input);
    test4osstream(input);
    return 0;
}
