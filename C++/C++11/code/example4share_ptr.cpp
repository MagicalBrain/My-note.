#include <iostream>
#include <memory>

using namespace std;
using std::shared_ptr;

int main() {
    shared_ptr<string> ptr;
    if (ptr == nullptr)
        cout << "ptr is nullptr" << endl;
    return 0;
}