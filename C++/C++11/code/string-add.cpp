#include <iostream>
#include <string>

using namespace std;
using std::string;

int main() {
    
    for (int i = 0; i < 10; i++) {
        //string in = "asdf" + i + ".txt";
        string in = "asdf" + i;
        cout << i << in << endl;
    }
    
    return 0;
}