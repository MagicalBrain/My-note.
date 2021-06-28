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

void CreateNewFamiliesKids(map<string, vector<string> > &families, string first_name, vector<string> names) {
    families.insert( make_pair(first_name, names));
}

void PrintFamilies(map<string, vector<string> > families) {
    if (families.empty()) {
        cout << "families 为空！" << endl;
        return;
    }

    for (auto i : families) {
        cout << i.first << endl;
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void AddNewKids(map<string, vector<string> > &families, string first_name, string names) {
    
    if (!families.empty()) {
        //如果families不为空，则
        string t;
        for (auto i : families) {
            if (i.first == first_name) {
                t = i.first;
                break;
            }
        }
        if (t.size() > 0) {
            families[t].push_back(names);
            return;
        }
        
    } 
    //如果families为空，则直接添加
    vector<string> tmp;
    tmp.push_back(names);
    pair<string, vector<string> > p = make_pair(first_name, tmp);
    families.insert(p);
    //return false;
}

int main() {
    map<string, vector<string> > familis;
    vector<string> names;
    string first_name, name;

    cout << "创建map" << endl;
    cout << "请输入姓" << endl;
    cin >> first_name;
    cout << "请输入孩子的名字：" << endl;
    while (cin >> name)
    {
        names.push_back(name);
    }
    CreateNewFamiliesKids(familis, first_name, names);
    
    PrintFamilies(familis);

    cout << "请输入孩子的姓名：" << endl;
    cin >> first_name >> name;
    AddNewKids(familis, first_name, name);

    PrintFamilies(familis);
    return 0;
}