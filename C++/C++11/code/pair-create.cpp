#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
using std::vector;
using std::string;
//using std::set;

pair<string, int> process(vector<string> &v) {
   //处理v
   if (!v.empty())
      //return {v.back(), v.back().size()};    //列表初始化
      return make_pair(v.back(), v.back().size());
   else
      return pair<string, int> ();     //隐式构造返回值
      //return make_pair();   //貌似make_pair不能生成空的pair类型的对象？
}

int main() {
    vector<string> v;
    string str;
    pair<string,int> re;

    while (cin >> str)
        v.push_back(str);

    cout << v.back() << " " << v.back().size() << endl;

    re = process(v);
    cout << re.first << " " << re.second << endl;
    return 0;
}