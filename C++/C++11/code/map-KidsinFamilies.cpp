/*
* 问题：创建一个map，用于存储一个家庭的孩子的姓名。
* 关键字为姓，值是一个vector为该家庭所有孩子的名
* 实现方法：
*    添加新家庭的孩子的姓名；
*    向已有家庭添加孩子的姓名；
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using std::vector;
using std::string;
using std::map;

bool AddNewFamiliesKids(map<string, vector<string> > &families, string first_name, vector<string> names) {
    if (!families.empty()) {

    } else {
        make_pair(first_name, names);
    }
    return false;
}

int main() {
    map<string, vector<string> > familis;
    vector<string> names;
    return 0;
}