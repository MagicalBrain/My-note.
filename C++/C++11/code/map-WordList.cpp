/*
* 定义一个map，将单词与一个行号的list关联， list中保存的是单词所出现的行号。
*/
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;
using std::vector;
using std::string;
using std::list;
using std::map;

int main() {
    map<string, list<int> > m;
    map<vector<int>::iterator, int > vi;
    map< list<int>::iterator, int > li;
    return 0;
}