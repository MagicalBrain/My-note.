#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    //以10分为一个分数段统计成绩的数量： 0~9， 10~19，. ..， 90 ~ 99， 1000 
    vector<unsigned> scores(11, 0); // 11个分数段，全都初始化为0
    unsigned grade;
    while (cin >> grade) {  //读取成绩
        auto i = scores.begin();
        if (grade <= 100)
        //只处理有效的成绩
        *(i + (grade / 10)) += 1;
        //++scores[grade / 10];
        //将对应分数段的计数值加1
    }

    for (auto i : scores)
        cout << i << " ";
    cout << endl;
    
    return 0;
}